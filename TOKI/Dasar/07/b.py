inp = int(input())
for i in range(inp - 1, -1, -1):
	a = " " * i
	b = "*" * (inp - i)
	print(a + b)