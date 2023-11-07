import numpy as np


def power_of_matrix(A, n):
    A2 = np.dot(A, A)
    if n == 0:
        return [
            [1, 0],
            [0, 1]
        ]

    elif n == 1:
        return A

    elif n % 2 == 1 and n > 1:

        return np.dot(A, (power_of_matrix(A2, (n - 1) / 2)))
    elif n % 2 == 0 and n > 1:
        return power_of_matrix(A2, n / 2)


n = int(input("Enter the value(n >= 2): "))

un = power_of_matrix([
    [1, 1],
    [1, 0]
], n - 1)

print(f"Fibonacci Number is {(np.dot(un, [[1], [1]])[0,0])}")
