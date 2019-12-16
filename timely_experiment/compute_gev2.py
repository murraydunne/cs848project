xrange=range
import numpy as np
import matplotlib.pylab as plt
from matplotlib.legend_handler import HandlerLine2D
import lmoments
import sys
import warnings as _warnings
from collections import OrderedDict
from numpy.random import randint as _randint

class InstabilityWarning(UserWarning):
    """Issued when results may be unstable."""
    pass

_warnings.simplefilter('always', InstabilityWarning)
_warnings.simplefilter('always', UserWarning)

the_vals = []
part_vals = []
#want = [7, 8, 9, 10, 11]
want = [12, 13, 14, 15, 16]
with open(sys.argv[1], 'r') as f:
    keeping = False
    for line in f:
        if '=' in line:
            are_keeping = False
            for x in want:
                if '-' + str(x) + '.' in line:
                    keeping = True
                    print("Keeping", line)
                    are_keeping = True
            if not are_keeping:
                keeping = False
                print("Not keeping", line)

            if len(part_vals) > 0:
                part_vals = part_vals[10:-10]
                the_vals.extend(part_vals)
                part_vals = []

        if '=' not in line and keeping:
            part_vals.append(max([int(x) for x in line.strip().split(',')]) / 100000000.0)

print(len(the_vals))

#plt.plot(np.sort(stage_1_vals))
#plt.plot(stage_1_vals)
#plt.show()
#exit()

#print(np.mean(stage_1_vals), np.mean(stage_2_vals), np.mean(stage_3_vals))

def bootstrap_ci(data, statfunction=np.average, alpha = 0.0001, 
                 n_samples = 10000):
    """
    Given a set of data ``data``, and a statistics function ``statfunction`` that
    applies to that data, computes the bootstrap confidence interval for
    ``statfunction`` on that data. Data points are assumed to be delineated by
    axis 0.
    
    This function has been derived and simplified from scikits-bootstrap 
    package created by cgevans (https://github.com/cgevans/scikits-bootstrap).
    All the credits shall go to him.
    **Parameters**
    
    data : array_like, shape (N, ...) OR tuple of array_like all with shape (N, ...)
        Input data. Data points are assumed to be delineated by axis 0. Beyond this,
        the shape doesn't matter, so long as ``statfunction`` can be applied to the
        array. If a tuple of array_likes is passed, then samples from each array (along
        axis 0) are passed in order as separate parameters to the statfunction. The
        type of data (single array or tuple of arrays) can be explicitly specified
        by the multi parameter.
    statfunction : function (data, weights = (weights, optional)) -> value
        This function should accept samples of data from ``data``. It is applied
        to these samples individually. 
    alpha : float, optional
        The percentiles to use for the confidence interval (default=0.05). The 
        returned values are (alpha/2, 1-alpha/2) percentile confidence
        intervals. 
    n_samples : int or float, optional
        The number of bootstrap samples to use (default=100)
        
    **Returns**
    
    confidences : tuple of floats
        The confidence percentiles specified by alpha
    **Calculation Methods**
    
    'pi' : Percentile Interval (Efron 13.3)
        The percentile interval method simply returns the 100*alphath bootstrap
        sample's values for the statistic. This is an extremely simple method of 
        confidence interval calculation. However, it has several disadvantages 
        compared to the bias-corrected accelerated method.
        
        If you want to use more complex calculation methods, please, see
        `scikits-bootstrap package 
        <https://github.com/cgevans/scikits-bootstrap>`_.
    **References**
    
        Efron (1993): 'An Introduction to the Bootstrap', Chapman & Hall.
    """

    def bootstrap_indexes(data, n_samples=10000):
        """
    Given data points data, where axis 0 is considered to delineate points, return
    an generator for sets of bootstrap indexes. This can be used as a list
    of bootstrap indexes (with list(bootstrap_indexes(data))) as well.
        """
        for _ in range(n_samples):
            yield _randint(data.shape[0], size=(data.shape[0],))    
    
    alphas = np.array([alpha / 2,1 - alpha / 2])

    data = np.array(data)
    tdata = (data,)
    
    # We don't need to generate actual samples; that would take more memory.
    # Instead, we can generate just the indexes, and then apply the statfun
    # to those indexes.
    bootindexes = bootstrap_indexes(tdata[0], n_samples)
    stat = np.array([statfunction(*(x[indexes] for x in tdata)) for indexes in bootindexes])
    stat.sort(axis=0)

    # Percentile Interval Method
    avals = alphas

    nvals = np.round((n_samples - 1)*avals).astype('int')

    if np.any(nvals == 0) or np.any(nvals == n_samples - 1):
        _warnings.warn("Some values used extremal samples; results are probably unstable.", InstabilityWarning)
    elif np.any(nvals<10) or np.any(nvals>=n_samples-10):
        _warnings.warn("Some values used top 10 low/high samples; results may be unstable.", InstabilityWarning)

    if nvals.ndim == 1:
        # All nvals are the same. Simple broadcasting
        return stat[nvals]
    else:
        # Nvals are different for each data point. Not simple broadcasting.
        # Each set of nvals along axis 0 corresponds to the data at the same
        # point in other axes.
        return stat[(nvals, np.indices(nvals.shape)[1:].squeeze())]

def ci_bootstrap(data, gevfit):
    # Calculate confidence intervals using parametric bootstrap and the
    # percentil interval method
    # This is used to obtain confidence intervals for the estimators and
    # the return values for several return values.    
    # More info about bootstrapping can be found on:
    #     - https://github.com/cgevans/scikits-bootstrap
    #     - Efron: "An Introduction to the Bootstrap", Chapman & Hall (1993)
    #     - https://en.wikipedia.org/wiki/Bootstrapping_%28statistics%29

    # parametric bootstrap for return levels and parameters   

    # The function to bootstrap     
    def func(data):
        sample = lmoments.randgev(len(data), gevfit)
        samgevfit = lmoments.pelgev(lmoments.samlmu(sample))      
                
        T = np.arange(0.1, 999.1, 0.1) + 1
        sT = lmoments.quagev(1.0-1./T, samgevfit)
        res = samgevfit
        res.extend(sT.tolist())
        return tuple(res)

    # the calculations itself
    out = bootstrap_ci(data, statfunction = func, n_samples = 500)
    ci_Td = out[0, 3:]
    ci_Tu = out[1, 3:]
    params_ci = OrderedDict()
    params_ci['shape']    = (out[0,0], out[1,0])
    params_ci['location'] = (out[0,1], out[1,1])
    params_ci['scale']    = (out[0,2], out[1,3])
    
    return{'ci_Td':ci_Td, 'ci_Tu':ci_Tu, 'params_ci':params_ci}


def do_it(data, title):
    print("AAAA")
    lmom = lmoments.samlmu(data)
    print("BBBB")
    gevfit = lmoments.pelgev(lmom) # the parameters of the GEV distribtion as estimated on data
    print(gevfit)

    # return years (1.1 to 1000)
    T  = np.arange(0.1, 999.1, 0.1) + 1
    sT = lmoments.quagev(1.0-1./T, gevfit)

    # prepare index for obs
    N    = np.r_[1:len(data)+1]*1.0 #must *1.0 to convert int to float
    Nmax = max(N)

    # get confidence intervals
    bootout   = ci_bootstrap(data, gevfit)
    ci_Td     = bootout["ci_Td"]
    ci_Tu     = bootout["ci_Tu"]
    params_ci = bootout["params_ci"]    

    fig, ax = plt.subplots()

    plt.setp(ax.lines, linewidth = 2, color = 'magenta')

    base_x = 10
    subs_x = [2, 3, 4, 5, 6, 7, 8, 9]

    ax.set_title("Execution Time GEV Distribution - " + title, fontsize=18)
    ax.set_xlabel("Expected Frequency of Extrema", fontsize=14)
    ax.set_ylabel("Maximum Execution Time", fontsize=14)
    ax.semilogx(T, sT, basex=base_x)
    #ax.plot(T, sT)
    ax.scatter(Nmax/N, np.sort(data)[::-1], color = 'orangered')

    ax.semilogx(T, ci_Td, '--', basex=base_x)
    #ax.plot(T, ci_Td, '--')
    ax.semilogx(T, ci_Tu, '--', basex=base_x)
    #ax.plot(T, ci_Tu, '--')
    ax.fill_between(T, ci_Td, ci_Tu, color = '0.75', alpha = 0.5)

    plt.show()

do_it(the_vals, "Frame Loading Stage")

