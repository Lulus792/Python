import pygame, sys
from partical import *
from simulate import boltzmann_distribution  
 

class Simulate:
    def __init__(this):
        pygame.init()
        this.screen = pygame.display.set_mode((WIDTH, HEIGHT))
        pygame.display.set_caption('Partical Simulation')

        this.particals:list[Partical] = [Partical()] * PARTICALS

    def run(this):
        while True:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    sys.exit()

            this.screen.fill(BLACK)
            boltzmann_distribution(this.particals)
            this.draw()
            #pygame.display.update()

    def draw(this):
        for partical in this.particals:
            pygame.draw.circle(this.screen, WHITE, 
                              (partical.pos.x, partical.pos.y), RADIUS_OF_PARTICAL, 1)

if __name__ == '__main__':
    simulation = Simulate()
    simulation.run()
