n = int(input())
for i in range(n):
	inp = int(input())
	ret = bin(inp - 1).count("1")
	print(ret % 3)	