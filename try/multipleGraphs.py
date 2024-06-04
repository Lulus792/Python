import matplotlib.pyplot as plt
import numpy as np

e = 2.71

def exp(x):
    return pow(e, x)

x = np.linspace(-1, 1, num=50)



plt.xlabel('x')
plt.ylabel('y')
plt.plot(x, exp(x))

plt.show()

