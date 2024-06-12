from partical import *

def checkIfParticalCollide(par1:Partical, par2:Partical) -> bool:
    min1_x:float = par1.pos.x - RADIUS_OF_PARTICAL;
    min2_x:float = par2.pos.x - RADIUS_OF_PARTICAL;
    min1_y:float = par1.pos.y - RADIUS_OF_PARTICAL;
    min2_y:float = par2.pos.y - RADIUS_OF_PARTICAL;
    min1_z:float = par1.pos.z - RADIUS_OF_PARTICAL;
    min2_z:float = par2.pos.z - RADIUS_OF_PARTICAL;

    max1_x:float = par1.pos.x + RADIUS_OF_PARTICAL;
    max2_x:float = par2.pos.x + RADIUS_OF_PARTICAL;
    max1_y:float = par1.pos.y + RADIUS_OF_PARTICAL;
    max2_y:float = par2.pos.y + RADIUS_OF_PARTICAL;
    max1_z:float = par1.pos.z + RADIUS_OF_PARTICAL;
    max2_z:float = par2.pos.z + RADIUS_OF_PARTICAL; 

    if (min1_x < min2_x and min2_x < max1_x) or (min1_x < max2_x and max2_x < max1_x): 
        return True
    elif (min1_y < min2_y and min2_y < max1_y) or (min1_y < max2_y and max2_y < max1_y): 
        return True
    elif (min1_z < min2_z and min2_z < max1_z) or (min1_z < max2_z and max2_z < max1_z): 
        return True

    return False

def inelastic_collision(par1:Partical, par2:Partical) -> None:
    pass

def setNewPositionOfPartical(partical:Partical) -> None:
    pass

def boltzmann_distribution(particals:list[Partical]) -> None:
    start:int = 0
    for i in range(len(particals)):
        for j in range(start, len(particals)):
            if i == j: continue
            if (checkIfParticalCollide(particals[i], particals[j])):
                inelastic_collision(particals[i], particals[j])
        setNewPositionOfPartical(particals[i])
        start += 1
