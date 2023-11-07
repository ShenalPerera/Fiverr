"""
    N(t) = N(0) (1/2) ^(t/y_half_life)
"""
import math
import numpy as np
import matplotlib.pyplot as plt


def calc_drug_amount(init_value, m, half_life, t):
    return (init_value * t) / m - ((init_value * t) / m) * math.pow(1 / 2, t / half_life)


M = 6
A = 20
H = 10

# Consider an Hour
initial_drug_amount = A

drugs_amount = []

time = np.arange(0, 241, 1)
for t in time:
    drugs_amount.append(calc_drug_amount(initial_drug_amount, M, H, t))

plt.figure(figsize=(10, 10))

plt.plot(time, drugs_amount)
plt.show()