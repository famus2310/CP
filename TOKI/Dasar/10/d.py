import math
def primeFact(x):
	if x == 1:
		print("1", end = "")
		return
	isFirst = True
	for i in range(2, int(math.sqrt(x)) + 1):
		now = 0
		while (x % i == 0):
			now += 1
			x //= i
		if (now == 0):
			continue
		if (not isFirst):
			print(" x ", end = "")
		else:
			isFirst = False
		print(i, end = "")
		if (now > 1):
			print("^%d" % now, end = "")
	if (x > 1):
		if(not isFirst):
			print(" x %d" % x, end = "")
		else:
			print(x, end = "")
n = int(input())
primeFact(n)
print("")