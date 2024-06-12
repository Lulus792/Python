from __future__ import annotations 
from random import uniform, randint
from math import sqrt

WIDTH:int = 1280 
HEIGHT:int = 800

MASS:float = 1.0
ENERGIE:float = 100.0
PARTICALS:int =  10
SIZE_OF_CUBE:float = 10.0
RADIUS_OF_PARTICAL:float = 0.1

BLACK = (255, 0, 0)
WHITE = (255, 255, 255)


class Vector3:
    def __init__(this):
        this.x:float = randint(0, SIZE_OF_CUBE)
        this.y:float = randint(0, SIZE_OF_CUBE)
        this.z:float = randint(0, SIZE_OF_CUBE) 
        

class v_Vector3:
    def __init__(this, partical:Partical):
        v_one_dimensional:float = sqrt(2 * partical.E / partical.m)
        this.v_x:float = uniform(0, v_one_dimensional) 
        this.v_y:float = uniform(0, (v_one_dimensional - this.v_x)) 
        this.v_z:float = v_one_dimensional - this.v_x - this.v_y 

class Partical:
    def __init__(this):
        this.pos:Vector3 = Vector3()
        this.m:float = MASS 
        this.E:float = ENERGIE
        this.v:v_Vector3 = v_Vector3(this)

    def calculate_speed(this):
        pass
