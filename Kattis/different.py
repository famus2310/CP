import math

def solve(a, b):
	return int(math.fabs(a - b))

while (True):
	try:
		a, b = map(int, input().split())
		print(solve(a, b))
	except EOFError:
		break