import math
def isPrime(x):
	now = 0
	for i in range(2, int(math.sqrt(x)) + 1):
		if x % i == 0:
			now += 1
			if (x / i != i):
				now += 1
		if now > 2:
			return False
	return True

n = int(input())
for i in range(n):
	inp = int(input())
	if isPrime(inp):
		print("YA")
	else:
		print("BUKAN")