arr = []
while(True):
	try:
		inp = int(input())
		arr.append(inp)
	except EOFError:
		arr.reverse()
		for i in arr:
			print(i)
		break
