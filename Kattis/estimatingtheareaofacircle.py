while(True):
	PI = 3.1415926535
	inp = list(map(float, input().split()))
	if (inp[0] == 0 and inp[1] == 0 and inp[2] == 0):
		break
	print(PI * inp[0] * inp[0], end = " ")
	print(inp[2] * 4 * inp[0] * inp[0] / inp[1])