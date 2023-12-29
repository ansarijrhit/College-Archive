from array import *
from pynput import keyboard
import time
from graphics import *
win = GraphWin(width = 660, height = 660) # create a window
win.setCoords(0, 0, 11, 11) # set the coordinates of the window; bottom left is (0, 0) and top right is (10, 10)

Board = []
ballX = 5
ballY = 5
velX = -1
velY = 1
score = 0
paddleY = 4
paddleY2 = 4

class Pong:
	def main(self):

		topRect = Rectangle(Point(0, 0), Point(11,1))
		topRect.setFill("black")
		topRect.draw(win)

		backRect = Rectangle(Point(0, 1), Point(1,11))
		backRect.setFill("black")
		backRect.draw(win)

		bottomRect = Rectangle(Point(1, 10), Point(11,11))
		bottomRect.setFill("black")
		bottomRect.draw(win)

		Board.insert(0, [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1])
		Board.insert(0, [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1])
		i = 0
		while i < 9:
			if i < 3 or i > 5:
				Board.insert(1, [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0])
			else:
				Board.insert(1, [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2])
			i = i + 1
		Board[ballX][ballY] = 3
		self.printBoard()
		# Pong.paint()
		i = 0
		while True:
			self.stepPaddle()
			if i % 100 == 0:
				Pong.step()
			time.sleep(.15)
			# Pong.printBoard()
	
	def printBoard(self):
		global paddleY
		for r in Board:
			for c in r:
				print(c, end = " ")
			print()
	
	def stepPaddle(self):
		paddleRect = Rectangle(Point(10, paddleY2-1), Point(11, paddleY2+1))
		paddleRect.setFill("blue")
		paddleRect.draw(win)
		i = 1
		while i < 10:
			if i >= paddleY-1 and i <= paddleY+1:
				Board[i][10] = 2
			else:
				Board[i][10] = 0
			i = i + 1

	def step(self):
		global ballX, ballY, velX, velY, score
		ball = Circle(Point(ballX, ballY), 1)
		ball.setFill("red")
		ball.draw(win)
		if ballY >= 10:
			Board[ballX][ballY] = 0
			score = score - 1
			ballX = 5
			ballY = 5
			velX = 1
		else:
			if Board[ballX+1][ballY] != 0 or Board[ballX-1][ballY] != 0:
				velY = velY*-1
			if Board[ballX][ballY+1] != 0 or Board[ballX][ballY-1] != 0:
				velX = velX*-1
			Board[ballX][ballY] = 0
			ballX = ballX+velY
			ballY = ballY+velX
			Board[ballX][ballY] = 3
	
	# def paint():
	# 	r = 0
	# 	c = 0
	# 	for row in Board:
	# 		for col in row:
	# 			rect = Rectangle(Point(c,r), Point((c+1),(r+1)))
	# 			if Board[r][c] == 0:
	# 				rect.setOutline("white")
	# 				rect.setFill("white")
	# 				rect.draw(win)
	# 			elif Board[r][c] == 1:
	# 				rect.setOutline("black")
	# 				rect.setFill("black")
	# 				rect.draw(win)
	# 			elif Board[r][c] == 2:
	# 				rect.setOutline("blue")
	# 				rect.setFill("blue")
	# 				rect.draw(win)
	# 			elif Board[r][c] == 2:
	# 				circle = circle(Point(r*60,c*60), 3)
	# 				circle.setFill("red")
	# 				circle.draw(win)
	# 			if c <= 9:
	# 				c = c+1
	# 		if r <= 9:
	# 			r = r+1
def on_press(key):
	global paddleY, paddleY2
	if key == keyboard.Key.esc:
		return False  # stop listener
	try:
		k = key.char  # single-char keys
	except:
		k = key.name  # other keys
	if k in ['w', 'up'] and paddleY > 2:  # keys of interest
		paddleY = paddleY-1
		paddleY2 = paddleY2+1
	elif k in ['s', 'down'] and paddleY < 8:  # keys of interest
		paddleY = paddleY+1
		paddleY2 = paddleY2-1
listener = keyboard.Listener(on_press=on_press)
listener.start()  # start to listen on a separate thread

Pong.main()