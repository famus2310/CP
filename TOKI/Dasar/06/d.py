now = 0
while(True):
	try:
		inp = int(input())
		now += inp
	except EOFError:
		print(now)
		break