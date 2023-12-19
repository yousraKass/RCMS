from matplotlib import pyplot as plt
import numpy as np

file_path = "runningTimeInsert.txt"

data1 = np.loadtxt(file_path)


x= data1[:,0]
y= data1[:,1]

plt.plot(x,y, color="blue")

plt.show()