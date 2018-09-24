import math
n = int(input())
for i in range(n):
	s = input()
	ans = ""
	length = len(s)
	length = int(math.sqrt(length))
	for j in range(length - 1, -1, -1):
		for k in range(j, len(s), length):
			ans += s[k]
	print(ans)