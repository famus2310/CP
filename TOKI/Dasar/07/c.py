inp = int(input())
now = 0
for i in range(1, inp + 1):
	for j in range(i):
		print(now, end = "")
		now += 1
		now %= 10
	print("")