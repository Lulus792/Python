import matplotlib.pyplot as plt
import matplotlib.animation as animation
import numpy as np

k_B:float = 1.381e-23
T:float = 273.0
m:float = 9.11e-31
e:float = 2.7182818284

def mb_dist(v:list[float]) -> list[float]:
    def f(v_tmp:float) -> float:
        tmp:float = 4 * np.pi * np.sqrt(pow(m / (2 * np.pi * k_B * T), 3))
        tmp *= pow(v_tmp, 2) * pow(e, -(m * pow(v_tmp, 2))/(2 * k_B * T))
        return tmp
    return [f(_v) for _v in v] 

def maxwell_boltzmann_distribution():
    v_max = np.sqrt(2 * k_B * T / m) * 5
    # x = np.linspace(0, v_max, num=1000, dtype=float)
    v = np.loadtxt('data.csv', dtype=float, skiprows=1)[:]
    #y = mb_dist(v) 

    #plt.plot(x, y)
    plt.hist(v, bins=100)
    plt.show()
