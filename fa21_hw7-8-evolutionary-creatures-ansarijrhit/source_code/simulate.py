import pybullet_data
import pybullet as p
import time as t
import pyrosim.pyrosim as pyrosim
import numpy
import sys
import os
from pyrosim.neuralNetwork import NEURAL_NETWORK

directOrGUI = sys.argv[1]
solutionID = sys.argv[2]

pi = numpy.pi

backLegAmplitude = pi/4.0
backLegFrequency = pi/48.0
backLegPhaseOffset = 0
frontLegAmplitude = pi/4.0
frontLegFrequency = pi/48.0
frontLegPhaseOffset = pi/4.0

if directOrGUI == "DIRECT":
    physicsClient = p.connect(p.DIRECT)
elif directOrGUI == "GUI":
    physicsClient = p.connect(p.GUI)

p.setAdditionalSearchPath(pybullet_data.getDataPath())


def Get_Fitness(id, link):
    stateOfLinkZero = p.getLinkState(id, link)
    positionOfLinkZero = stateOfLinkZero[0]
    xCoordinateOfLinkZero = positionOfLinkZero[0]
    f = open("tmp" + solutionID + ".txt", "w")
    f.write(str(xCoordinateOfLinkZero))
    f.close()
    os.system("mv tmp" + solutionID + ".txt fitness" + solutionID + ".txt")

p.setGravity(0,0,-9.8)
planeId = p.loadURDF("plane.urdf")
robot = p.loadURDF("body.urdf")
p.loadSDF("world.sdf")
pyrosim.Prepare_To_Simulate("body.urdf")
backLegSensorValues = numpy.zeros(1000)
frontLegSensorValues = numpy.zeros(1000)

nn = NEURAL_NETWORK("brain" + solutionID + ".nndf")
os.system("rm brain" + solutionID + ".nndf")

backLegTargetAngles = numpy.sin(numpy.linspace(-pi, pi, 1000))*pi/4.0
frontLegTargetAngles = numpy.sin(numpy.linspace(-pi, pi, 1000))*pi/4.0
for i in range(1000):
    backLegTargetAngles[i] = backLegAmplitude * numpy.sin(backLegFrequency * i + backLegPhaseOffset)
    frontLegTargetAngles[i] = frontLegAmplitude * numpy.sin(frontLegFrequency * i + frontLegPhaseOffset)
# numpy.save("data/backLegTargetAngles.npy", backLegTargetAngles)
# numpy.save("data/frontLegTargetAngles.npy", frontLegTargetAngles)
# exit()


for i in range(1000):
    p.stepSimulation()

    # Sense
    backLegSensorValues[i] = pyrosim.Get_Touch_Sensor_Value_For_Link("BackLeg")
    frontLegSensorValues[i] = pyrosim.Get_Touch_Sensor_Value_For_Link("FrontLeg")

    # Think
    nn.Update()
    # nn.Print()

    # Act
    for neuronName in nn.Get_Neuron_Names():
        if nn.Is_Motor_Neuron(neuronName):
            jointName = nn.Get_Motor_Neurons_Joint(neuronName)
            desiredAngle = nn.Get_Value_Of(neuronName)
            pyrosim.Set_Motor_For_Joint(
                bodyIndex = robot,
                jointName = jointName,
                controlMode = p.POSITION_CONTROL,
                targetPosition = desiredAngle,
                maxForce = 40)
        
        if directOrGUI == "GUI":
            t.sleep(1/1000)

# numpy.save("data/backLegSensorValues.npy", backLegSensorValues)
# numpy.save("data/frontLegSensorValues.npy", frontLegSensorValues)
Get_Fitness(robot, 0)
p.disconnect()
