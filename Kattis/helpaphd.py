N = int(input())
for i in range(N):
	line = input().split('+')
	if (line[0] == "P=NP"):
		print("skipped")
	else:
		print(int(line[0]) + int(line[1]))
