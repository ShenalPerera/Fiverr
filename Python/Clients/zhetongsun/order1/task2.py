"""
    y = a e^bx
    lny = lna + ln(e^bx)
    lny = lna + b(x=x0)
    z   = c   + mx
    a = e^c
    b = m

"""
import math

import matplotlib.pyplot as plt
import numpy as np

x1 = np.array([1.19, 2.85, 5.00, 5.36, 6.12, 6.17, 6.82, 8.51, 9.31])
y1 = np.array([9.9062E-1, 1.2317E-1, 1.0219E-2, 7.0374E-3, 2.4345E-3, 2.4406E-3, 1.1422E-3, 1.4849E-4, 5.5660E-5])



def log_transform(yvals):
    lny = []
    for val in yvals:
        lny.append(math.log(val, math.e))
    return np.array(lny)


def linear_regression(x, y):
    x_mean = x.mean()
    y_mean = y.mean()

    B1_num = ((x - x_mean) * (y - y_mean)).sum()
    B1_den = ((x - x_mean) ** 2).sum()
    gradient = B1_num / B1_den

    c = y_mean - (gradient * x_mean)

    reg_line = 'y = {} + {}m'.format(c, round(gradient, 3))

    return c, gradient, reg_line


# transformed_yvals = log_transform(y1)
# c, m, line_equation = linear_regression(x1, transformed_yvals)
#
# a = math.exp(c)
# b = m


# def plot_equation1(a, b, x_vals, y_vals):
#     x = np.linspace(1, 15, 20)
#     y = []
#     for val in x:
#         y.append(a * math.exp(b * val))
#     y = np.array(y)
#     plt.figure(figsize=(10,10))
#     plt.subplot(1, 2, 1)
#     plt.loglog(x, y)
#     plt.scatter(x_vals, y_vals)
#     plt.title("Model (Log-Log scale)")
#
#     plt.subplot(1, 2, 2)
#     plt.plot(x, y)
#     plt.scatter(x_vals,y_vals)
#     plt.title("Cartesian plane")
#     plt.show()


lnx = log_transform(x1)
lny = log_transform(y1)

b, m, equation = linear_regression(lnx, lny)

print(f"Values after performing linear regression m = {m} and b = {b}")
print(f"\nRequired power function is y = e^b * x^m =" + "{:.3f}".format(math.exp(b)), end="* x^")
print("{:.3f}".format(m))

plt.figure(figsize=(10, 10))
plt.subplot(1, 2, 1)
plt.semilogy(x1, y1)
plt.scatter(x1, y1)
plt.title("Model (Semi-Log scale)")

plt.subplot(1, 2, 2)
plt.loglog(x1, y1)
plt.scatter(x1, y1)
plt.title("Model (Semi-Log scale)")

plt.show()
