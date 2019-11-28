import matplotlib.pyplot as plt
import numpy as np
import sys

vals = []

with open(sys.argv[1]) as f:
    for line in f:
        sline = line.strip()
        if sline.startswith("Time to run ML on frame") and 'node 15' not in sline and 'node 16' not in sline:
            frame = int(sline.split(" ")[6])
            val = int(sline.split(" ")[8])
            vals.append(val)


vals = np.array(vals)[10:-10]

plt.hist(vals, 100)
plt.title("ML Node Execution Time Histogram", fontsize=28)
plt.xlabel("Execution Time", fontsize=22)
plt.ylabel("Number of Frontiers", fontsize=22)
plt.show()  