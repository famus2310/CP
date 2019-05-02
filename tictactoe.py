import math
import random


ismax = {}

def isvalid(x, y) :
	return x >= 0 and x < 3 and y >= 0 and y < 3

def check(state) : 
	now = state[0] + state[1] + state[2]
	if (now == "111") :
		return 1
	elif (now == "222") :
		return -1
	now = (state[3]) + (state[4]) + (state[5])
	if (now == "111") :
		return 1
	elif (now == "222") :
		return -1
	now = (state[6]) + (state[7]) + (state[8])
	if (now == "111") :
		return 1
	elif (now == "222") :
		return -1
	now = (state[0]) + (state[3]) + (state[6])
	if (now == "111") :
		return 1
	elif (now == "222") :
		return -1
	now = (state[1]) + (state[4]) + (state[7])
	if (now == "111") :
		return 1
	elif (now == "222") :
		return -1
	now = (state[2]) + (state[5]) + (state[8])
	if (now == "111") :
		return 1
	elif (now == "222") :
		return -1
	now = (state[0]) + (state[4]) + (state[8])
	if (now == "111") :
		return 1
	elif (now == "222") :
		return -1
	now = (state[2]) + (state[4]) + (state[6])
	if (now == "111") :
		return 1
	elif (now == "222") :
		return -1
	return 0


def minimax(state, turn) :
	# print(state)
	if (check(state) == 1) :
		ismax[state] = 1
		return 1
	elif (check(state) == -1) :
		ismax[state] = -1
		return -1
	if (state in ismax) :
		return ismax[state]
	if (turn == 0) :
		ismax[state] = -2
		for i in range(9) :
			if (state[i] == '0') :
				tmp = state[:i] + '1' + state[i + 1:]
				ismax[state] = max(ismax[state], minimax(tmp, 1))
		if (ismax[state] == -2) :
			ismax[state] = 0
	else :
		ismax[state] = 2
		for i in range(9) :
			if (state[i] == '0') :
				tmp = state[:i] + '2' + state[i + 1:]
				ismax[state] = min(ismax[state], minimax(tmp, 0))
		if (ismax[state] == 2) :
			ismax[state] = 0
	return ismax[state]


def decide(state) :
	mxnow = 2
	curstate = ""
	for i in range(9) :
		if (state[i] == '0') :
			tmp = state[:i] + '2' + state[i + 1:]
			# print(tmp, ismax[tmp])
			if (ismax[tmp] < mxnow) :
				# print("masuk pak eko")
				mxnow = ismax[tmp]
				curstate = tmp
	# print(mxnow)
	return curstate

def printBoard(state, final) :
	if (final == 0) :
		print("CURRENT BOARD STATE")
	else :
		print("FINAL BOARD STATE")
	print(" - - - ")
	for x in range(3) :
		print("|", end = "")
		for y in range(3) :
			now = state[int(x * 3 + y)]
			if now == '1' :
				print('X', end = "|")
			elif now == '2' :
				print('O', end = "|")
			else :
				print(' ', end = "|")
		print("")
		print(" - - - ")
	print("")

def checkGameOver(state) :
	if (check(state) == 1):
		return 1
	if (check(state) == -1) :
		return -1
	zero = 0
	for i in range(9) :
		if (state[i] == '0') :
			zero = zero + 1
	if (zero == 0) :
		return 0
	return -2

now = '0' * 9
minimax(now, 0)

print("|-----------------------------------------------------------------------------------------------|")
print("| Running Tic-Tac-Toe Using Minimax Algorithm with Dynamic Programming Memoization Optimization |")
print("|-----------------------------------------------------------------------------------------------|")
print("")

while (1) :
	# print(check("112202112"))
	while (1) :
		printBoard(now, 0)
		x, y = map(int, input().split())
		curinput = int(3 * x + y)
		if (isvalid(x, y) and now[curinput] == '0') :
			break
		print ("INVALID MOVE")
		print("")

	now = now[:curinput] + '1' + now[curinput + 1:]
	# print(now)
	if (checkGameOver(now) == 1) :
		print("YOU WIN!!")
		break
	elif (checkGameOver(now) == -1) :
		print("YOU LOSE!!")
		break
	elif (checkGameOver(now) == 0) :
		print("DRAW!!")
		break

	now = decide(now)
	if (checkGameOver(now) == 1) :
		print("YOU WIN!!")
		break
	elif (checkGameOver(now) == -1) :
		print("YOU LOSE!!")
		break
	elif (checkGameOver(now) == 0) :
		print("DRAW!!")
		break
printBoard(now, 1)
	# print(now)


