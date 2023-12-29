import numpy
import matplotlib.pyplot as pyplot

backLegSensorValues = numpy.load("data/backLegSensorValues.npy")
frontLegSensorValues = numpy.load("data/frontLegSensorValues.npy")
backLegTargetAngles = numpy.load("data/backLegTargetAngles.npy")
frontLegTargetAngles = numpy.load("data/frontLegTargetAngles.npy")

pyplot.plot(backLegTargetAngles)
pyplot.plot(frontLegTargetAngles)

# pyplot.plot(backLegSensorValues, label="Back Leg", linewidth=4)
# pyplot.plot(frontLegSensorValues, label="Front Leg")
# pyplot.legend()
pyplot.show()