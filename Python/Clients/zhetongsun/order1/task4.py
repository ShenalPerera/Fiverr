import numpy as np
import matplotlib.pyplot as plt

n = int(input("Enter a non-negative integer: "))

arr = np.zeros(n + 1, int)
arr[0] = 1
arr[1] = 0
arr[2] = 2

for i in range(0, n - 2):
    arr[i + 3] = 2 * arr[i + 2] - arr[i + 1] + arr[i] + i + 3

x_labels = np.arange(0, n + 1)

plt.title("U(n+3) = 2 * U(n+2) - U(n+1) + U(n) + n+ 3")
plt.xlabel("K values")
plt.ylabel("U(n)")

plt.plot(x_labels, arr)
plt.show()
