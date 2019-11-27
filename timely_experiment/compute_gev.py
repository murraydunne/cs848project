import numpy as np
import matplotlib.pylab as plt
from matplotlib.legend_handler import HandlerLine2D
import lmoments
import sys

stage_1_vals = []
stage_2_vals = []
stage_3_vals = []

with open(sys.argv[1]) as f:
    for line in f:
        sline = line.strip()

        if sline.startswith("Time to load frame"):
            stage_1_vals.append(int(sline.split(" ")[6]))
        elif sline.startswith("Time to run ML on frame"):
            stage_2_vals.append(int(sline.split(" ")[8]))
        elif sline.startswith("Time to decide object on frame"):
            stage_2_vals.append(int(sline.split(" ")[8]))

stage_1_vals = np.array(stage_1_vals)
stage_2_vals = np.array(stage_2_vals)
stage_3_vals = np.array(stage_3_vals)

print(np.mean(stage_1_vals), np.mean(stage_2_vals), np.mean(stage_3_vals))