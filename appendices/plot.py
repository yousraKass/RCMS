import matplotlib.pyplot as plt
import numpy as np


file_path1 = "runningTimeInsertCountry.txt"

data1 = np.loadtxt(file_path1)



x1= data1[:,0]
y1= data1[:,1]




plt.plot(x1,y1, color="blue", label = "search in AVL")


plt.legend()

plt.xlabel('number of restaurants')
plt.ylabel('running time in microseconds')
plt.title('search in AVL vs BST tree')

plt.show()