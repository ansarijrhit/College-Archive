import neat
import os
import random
import pygame

pygame.init()

# Define black and white
BLACK = (0,0,0)
WHITE = (255,255,255)
 
# Open a new window
size = (800, 600)
screen = pygame.display.set_mode(size)
pygame.display.set_caption("Pong")

clock = pygame.time.Clock()

generations = 0

SPEED = 1 # Change speed multiplier- speeds up training but might cause weird collision errors

class Ball:
    def __init__(self, dVec, speed=14, color=WHITE):
            self.dVec = pygame.math.Vector2(dVec).normalize() # Direction
            self.speed = speed
            self.surface = pygame.Surface((8, 8))
            self.surface.fill(color)
            self.pos = pygame.math.Vector2((0, 0))
            self.rec = self.surface.get_rect()
    
    def bounce(self, x, y):
        self.dVec.x *= x
        self.dVec.y *= y

    def move(self):
        self.pos.x += self.speed*SPEED*self.dVec.x
        self.pos.y += self.speed*SPEED*self.dVec.y
        self.rec.center = self.pos.x, self.pos.y

    def setSpeed(self, s):
        self.speed = s

    def setdVec(self, dv):
        self.dVec = dv

    def setPos(self, pos):
        self.pos = pos


class Paddle:
    colTop = False
    colBottom = False
    dead = False
    dVec = 0

    def __init__(self, speed = 10, color=WHITE):
        self.speed = speed
        self.surface = pygame.Surface((20, 80))
        self.surface.fill(color)
        self.pos = pygame.math.Vector2((780 , 300))
        self.rec = self.surface.get_rect()

    def move(self, dv):
        self.dVec = dv
        self.pos.y += self.speed*SPEED*self.dVec
        self.rec.center = 780, self.pos.y
        
        # Stay in bounds
        if self.rec.top <= 0:
            self.colTop = True
            self.colBottom = False
        elif self.rec.bottom >= 600:
            self.colTop = False
            self.colBottom = True 
        else:
            self.colTop = False
            self.colBottom = False 
    
    def setDead(self, d):
        self.dead = d

    def setSpeed(self, s):
        self.speed = s


# Check for collision with wall or paddle, returns true if collision paddle
def detectCollision(ball, paddle):
    # Change speeds based on x value (makes training take less time and easier to watch)
    if ball.rec.right <= 400:
        ball.setSpeed(25)
        paddle.setSpeed(16)
    else:
        ball.setSpeed(14)
        paddle.setSpeed(10)

    # Collision with walls
    if ball.rec.left <= 4:
        ball.setPos(pygame.math.Vector2((13, ball.pos.y)))
        ball.bounce(-1, 1)

    if ball.rec.top <= 4:
        ball.setPos(pygame.math.Vector2((ball.pos.x, 13)))
        ball.bounce(1, -1)
        
    elif ball.rec.bottom >= 596:  
        ball.setPos(pygame.math.Vector2((ball.pos.x, 587)))
        ball.bounce(1, -1)

    # Paddle missed
    elif ball.rec.right >= 796:  
        paddle.setDead(True)

    # Collision with paddle
    elif ball.rec.colliderect(paddle.rec):
        ball.bounce(-1,1)
        ball.setPos(pygame.math.Vector2((755, ball.pos.y)))
        ball.setdVec(pygame.math.Vector2((ball.dVec.x + random.uniform(-.3, .3), ball.dVec.y + random.uniform(-.3, .3))).normalize())
        return True
    return False
        
        
# Draw everything
def draw(balls, paddles):
    # Line down middle
    pygame.draw.line(screen, WHITE, (399, 0), (399, 600), 2)

    # Balls
    for ball in balls:
        screen.blit(ball.surface, (ball.rec.left, ball.rec.top))

    # Paddles
    for paddle in paddles:
        screen.blit(paddle.surface, (paddle.rec.left, paddle.rec.top))


def eval_genomes(genomes, config):
    global generations

    genomes2 = []
    nets = []
    balls = []
    paddles = []

    for _, genome in genomes:
        genome.fitness = 0
        net = neat.nn.FeedForwardNetwork.create(genome, config)
        randColor = (random.uniform(0,255), random.uniform(0,255), random.uniform(0,255))
        genomes2.append(genome)
        nets.append(net)    
        balls.append(Ball(dVec=(1, random.uniform(-0.8, -.05)), color=randColor))
        paddles.append(Paddle(color=randColor))

    generations += 1

    while len(paddles) > 0:  # Game loop
        for event in pygame.event.get():
            if event.type == pygame.QUIT: 
                pygame.quit()
        
        clock.tick(50) # Advance game
        screen.fill((0, 0, 54)) # Fill screen with dark blue
        draw(balls, paddles) # Draw balls and paddles
        font = pygame.font.SysFont(None, 30)
        count = font.render(f"Generation: {generations}", False, WHITE)
        screen.blit(count, (415,20)) # Display current generation

        # Evaluate fitness of paddles
        i = 0
        for paddle in paddles:
            success = False
            collision = detectCollision(balls[i], paddle)

            balls[i].move()

            if collision:
                genomes2[i].fitness += 1  # Ball hit, fitness increased
                if genomes2[i].fitness >= 10: # Reached desired fitness
                    success = True

            if paddle.dead or success:
                nets.remove(nets[i])
                paddles.remove(paddle)
                genomes2.remove(genomes2[i])
                balls.remove(balls[i])
                i -= 1    
            
            if i >= 0:
                direction = 3*nets[i].activate((balls[i].pos.y, paddle.pos.y))[0] # Train using ball y and paddle y
                if direction > 2 and not paddle.colBottom:
                    paddle.move(1) # Move down
                elif direction < 2 and direction > 1:
                    paddle.move(0) # Stop moving
                elif not paddle.colTop:
                    paddle.move(-1) # Move up
            i += 1

        # Update screen
        pygame.display.flip()


def run(config_file):
    config = neat.Config(neat.DefaultGenome, neat.DefaultReproduction,
                         neat.DefaultSpeciesSet, neat.DefaultStagnation,
                         config_file)

    # Create the population, which is the top-level object for a NEAT run.
    p = neat.Population(config)

    # Add a stdout reporter to show progress in the terminal.
    p.add_reporter(neat.StdOutReporter(True))
    stats = neat.StatisticsReporter()
    p.add_reporter(stats)
    p.add_reporter(neat.Checkpointer(5))

    # Run for up to 300 generations.
    winner = p.run(eval_genomes, 300)

    # Display the winning genome.
    print('\nBest genome:\n{!s}'.format(winner))


if __name__ == '__main__':
    # Determine path to configuration file. This path manipulation is
    # here so that the script will run successfully regardless of the
    # current working directory.
    local_dir = os.path.dirname(__file__)
    config_path = os.path.join(local_dir, 'config-feedforward')
    run(config_path)