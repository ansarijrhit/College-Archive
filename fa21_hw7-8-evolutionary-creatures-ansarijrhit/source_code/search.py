import os
import parallelhillclimber

phc = parallelhillclimber.PARALLEL_HILL_CLIMBER()

phc.EVOLVE()
phc.Show_Best()

# for i in range(5):
#     os.system("python3 generate.py")
#     os.system("python3 simulate.py")
