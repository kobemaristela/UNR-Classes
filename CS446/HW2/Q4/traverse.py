import os, math
import numpy as np
from scipy import stats
import matplotlib.pyplot as plt

# Utilizes Freedman Diaconis Rule 
def OptimalBins(data):
    tempData = np.asarray(data, dtype=np.float_)
    IQR = stats.iqr(tempData, rng=(25, 75), scale=1.0, nan_policy="omit")
    mySize = tempData.size
    myWidth = (2 * IQR) / np.power(mySize, 1/3)

    return myWidth

# Calculates # of bins based on width given
def CalculateBins(data,width):
    tempData = np.asarray(data, dtype=np.float_)
    datamin, datamax = tempData.min(), tempData.max()
    datarng = datamax - datamin
    bins = int((datarng / width) + 1)

    return bins


dirName = input("Please enter directory: ")
if not os.path.isdir(dirName):
    print("Invalid directory")
    exit()

data = []
for (dirpath, dirnames, filenames) in os.walk(dirName):
    for file in filenames:
        data.append(os.path.getsize(os.path.join(dirpath,file)))

# Calculate # of bins and width
optimal = OptimalBins(data)

user = True
while (user != 'y'):
    width = int(input(f"Please enter bin width (optimal width-> {math.floor(optimal)} bytes): "))
    myBins = CalculateBins(data,width)

    print(f"Based on bin width ({width}), there will be {myBins} bins created.")
    if (myBins > 500):
        print(f"Warning: Choosing bin count over 500 will slow down plotting...")
    user = input(f"Do you wish to continue (y/n)? ")


# Plot histogram
fig, ax = plt.subplots(nrows=1, ncols=1)
fig.set_size_inches(11, 8)
ax.hist(data, myBins, color="#FFFFFF", edgecolor="black")
ax.set_title("Directory File Size Historgram (Frequency vs Bins)", fontsize=14, loc="center")
ax.set_xlabel(f"Bins (Bin Width: {width} | Bin Count: {myBins})", fontsize=12)
ax.set_ylabel("Frequency (count)", fontsize=12)
ax.grid(False)
ax.set_facecolor(None)
plt.tight_layout()
plt.show()

