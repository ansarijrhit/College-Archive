import numpy
import pyrosim.pyrosim as pyrosim
import random
import os
import time

length = 1
width  = 1
height = 1
x = 0
y = 0
z = 0.5

class SOLUTION:
    def __init__(self, myID):
        self.weights = numpy.random.rand(3,2)
        self.weights = self.weights * 2 - 1
        self.myID = myID

    def Set_ID(self, id):
        self.myID = id

    def Start_Simulation(self, directOrGUI):
        self.Create_World()
        self.Generate_Body()
        self.Generate_Brain()
        os.system("python3 simulate.py " + directOrGUI + " " + str(self.myID) + " 2&>1 &")

    def Wait_For_Simulation_To_End(self):
        fitnessFileName = "fitness" + str(self.myID) + ".txt"
        while not os.path.exists(fitnessFileName):
	        time.sleep(0.01)
        f = open(fitnessFileName, "r")
        self.fitness = float(f.read())
        f.close()
        os.system("rm " + fitnessFileName)

    def Create_World(self):
        pyrosim.Start_SDF("world.sdf")
        pyrosim.Send_Cube(name="Box", pos=[x-3, y+3, z] , size=[length,width,height])
        pyrosim.End()

    def Generate_Body(self):
        pyrosim.Start_URDF("body.urdf")
        pyrosim.Send_Cube(name="Torso", pos=[1.5, y, 1.5] , size=[length,width,height])
        pyrosim.Send_Joint(name = "Torso_BackLeg" , parent= "Torso" , child = "BackLeg" , type = "revolute", position = "1 0 1")
        pyrosim.Send_Cube(name="BackLeg", pos=[-.5, y, -.5] , size=[length,width,height])
        pyrosim.Send_Joint(name = "Torso_FrontLeg" , parent= "Torso" , child = "FrontLeg" , type = "revolute", position = "2 0 1")
        pyrosim.Send_Cube(name="FrontLeg", pos=[.5, y, -.5] , size=[length,width,height])
        pyrosim.End()

    def Generate_Brain(self):
        pyrosim.Start_NeuralNetwork("brain" + str(self.myID) + ".nndf")
        pyrosim.Send_Sensor_Neuron(name = 0 , linkName = "Torso")
        pyrosim.Send_Sensor_Neuron(name = 1 , linkName = "BackLeg")
        pyrosim.Send_Sensor_Neuron(name = 2 , linkName = "FrontLeg")
        pyrosim.Send_Motor_Neuron( name = 3 , jointName = "Torso_BackLeg")
        pyrosim.Send_Motor_Neuron( name = 4 , jointName = "Torso_FrontLeg")

        for i in range(3):
            for j in range(2):
                pyrosim.Send_Synapse( sourceNeuronName = i , targetNeuronName = j+3 , weight = self.weights[i][j])

        pyrosim.End()
    
    def Mutate(self):
        r = random.randint(0,2)
        c = random.randint(0,1)
        self.weights[r][c] = random.random() * 2 - 1