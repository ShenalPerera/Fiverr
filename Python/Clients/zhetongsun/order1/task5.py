import numpy as np
import matplotlib.pyplot as plt

"""
    for the males
    m(n+1) = m(n) - am * m(n) + km * f(n)
    f(n+1) = f(n) - af * f(n) + kf * f(n)
    Total = t(n)
    t(n+1) = m(n) + f(n) 
"""
am = 0.25
af = 0.2
km = 0.54
kf = 0.50

female = np.zeros(11, int)
male = np.zeros(11, int)

female[0] = 600
male[0] = 1000


def calculate_population(data, a, k):
    for i in range(0, 10):
        data[i + 1] = data[i] - a * data[i] + k * data[i]


calculate_population(female, af, kf)
calculate_population(male, am, km)

x_labels = np.arange(0, 11)

plt.title("Population")
plt.xlabel("Kth Generation")
plt.ylabel("Population")

plt.plot(x_labels, female, label="female")
plt.plot(x_labels, male, label="male")
plt.legend()
plt.show()
