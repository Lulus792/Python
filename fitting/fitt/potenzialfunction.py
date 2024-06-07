from random import uniform
import matplotlib.pyplot as plt
from numpy import linspace
from random import uniform, randint
from scipy.optimize import curve_fit

def square_error(x:list, a, b, c):
    ret = [] 
    for val in x:
        ret.append(a*pow(val, 2) + b*val + c + randint(1, 2))
    return ret

def square(x, a, b, c):
    return a*pow(x, 2) + b*x + c

def potenzfunction():
    x = linspace(-5, 5, num=50) 
    y = square_error(x, 2, 0.75, -1)

    popt, _ = curve_fit(square, x, y)
    a, b, c = popt

    x_fitt = linspace(min(x), max(x), num=len(x))
    y_fitt = square(x_fitt, a, b, c)

    plt.plot(x, y)
    plt.plot(x_fitt, y_fitt, '--', color='red')

    plt.show()
