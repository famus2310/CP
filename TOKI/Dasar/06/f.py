inp = int(input())
for div in range(1, inp + 1):
	if inp % div == 0:
		print(inp // div)