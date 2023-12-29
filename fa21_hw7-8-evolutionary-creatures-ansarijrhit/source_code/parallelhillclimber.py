import solution
import copy
import os

numberOfGenerations = 10
populationSize = 10

class PARALLEL_HILL_CLIMBER:
    def __init__(self):
        os.system("rm brain*.nndf")
        os.system("rm fitness*.txt")
        self.parents = {}
        self.nextAvailableID = 0
        for i in range(populationSize):
            self.parents[i] = solution.SOLUTION(self.nextAvailableID)
            self.nextAvailableID += 1

    def EVOLVE(self):
        self.Evaluate(self.parents)
        for currentGeneration in range(numberOfGenerations):
            self.Evolve_For_One_Generation()

    def Show_Best(self):
        worst = self.parents[0]
        for i in self.parents:
            if worst.fitness > self.parents[i].fitness:
                worst = self.parents[i]
        worst.Start_Simulation("GUI")
    
    def Evolve_For_One_Generation(self):
        self.Spawn()
        self.Mutate()
        self.Evaluate(self.children)
        # self.Print()
        self.Select()

    def Print(self):
        print("")
        for i in self.parents:
            print(self.children[i].fitness, self.parents[i].fitness)

    def Evaluate(self, solutions):
        for i in range(populationSize):
            solutions[i].Start_Simulation("DIRECT")
        for i in range(populationSize):
            solutions[i].Wait_For_Simulation_To_End()
            # print(solutions[i].fitness)

    def Spawn(self):
        self.children = {}
        for i in self.parents:
            self.children[i] = copy.deepcopy(self.parents[i])
            self.children[i].Set_ID(self.nextAvailableID)
            self.nextAvailableID += 1

    def Mutate(self):
        for i in self.children:
            self.children[i].Mutate()

    def Select(self):
        for i in self.parents:
            if self.parents[i].fitness > self.children[i].fitness:
                self.parents[i] = self.children[i]