import math
def isPrime(x):
	if x == 1: 
		return False
	for i in range(2, int(math.sqrt(x)) + 1):
		if (x % i == 0):
			return False
	return True

n = int(input())
for i in range(n):
	inp = int(input())
	if (isPrime(inp)):
		print("YA")
	else:
		print("BUKAN")
