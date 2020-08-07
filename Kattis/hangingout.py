line = [int(x) for x in input().split()]
now = 0
denied = 0
for event in range(line[1]):
	inp = input().split()
	if inp[0][0] == "e":
		if now + int(inp[1]) <= line[0]:
			now += int(inp[1])
		else:
			denied += 1
	else:
		now -= int(inp[1])
print(denied)
