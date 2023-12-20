import matplotlib.pyplot as plt
import numpy as np


file_path1 = "runningTimeInsertAVL.txt"
file_path2 = "runningTimeInsertBst.txt"

data1 = np.loadtxt(file_path1)
data2 = np.loadtxt(file_path2)


x1= data1[:,0]
y1= data1[:,1]

x2= data2[:,0]
y2= data2[:,1]


plt.plot(x1,y1, color="blue", label = "insert in AVL")
plt.plot(x2,y2, color = "green", label = "insert in BST")


plt.legend()

plt.xlabel('number of restaurants')
plt.ylabel('running time in microseconds')
plt.title('insert in AVL vs BST tree')

plt.show()