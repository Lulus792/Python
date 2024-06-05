from numpy import linspace, arange
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
from random import uniform 


def linear():
    def calc_y(x, a = 1, b = 0):
        y = []
        for val in x:
            y.append(a * val + b + uniform(0, 0.2))
        return y

    def linear_fitt(x:list[any], a, b):
        return a * x + b

    x = linspace(0, 10, num=50)
    y = calc_y(x, 0.5, 1)

    popt, _ = curve_fit(linear_fitt, x, y)
    a, b = popt

    x_line = arange(min(x), max(x), 1)
    # calculate the output for the range
    y_line = linear_fitt(x_line, a, b)
    # create a line plot for the mapping function
    plt.plot(x, y)
    plt.plot(x_line, y_line, '--', color='red')
    plt.show()
