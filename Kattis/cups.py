def is_integer(x):
	try:
		i = int(x)
	except:
		return False
	return True

N = int(input())

arr = []

for i in range(N):
	line = input().split()
	if is_integer(line[0]):
		arr.append((int(line[0]), line[1]))
	else:
		arr.append((int(line[1]) * 2, line[0]))

arr.sort()
for i in range(N):
	print(arr[i][1])
