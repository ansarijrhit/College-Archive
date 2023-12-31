import solution
import copy

numberOfGenerations = 10

class HILL_CLIMBER:
    def __init__(self):
        self.parent = solution.SOLUTION()

    def EVOLVE(self):
        self.parent.EVALUATE("DIRECT")
        for currentGeneration in range(numberOfGenerations):
            self.Evolve_For_One_Generation()

    def Show_Best(self):
        self.parent.EVALUATE("GUI")
    
    def Evolve_For_One_Generation(self):
        self.Spawn()
        self.Mutate()
        self.child.EVALUATE("DIRECT")
        print("")
        print(self.child.fitness, self.parent.fitness)
        self.Select()

    def Spawn(self):
        self.child = copy.deepcopy(self.parent)

    def Mutate(self):
        self.child.Mutate()

    def Select(self):
        if self.parent.fitness < self.child.fitness:
            self.parent = self.child