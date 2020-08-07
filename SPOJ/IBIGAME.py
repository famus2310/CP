import math

n = int(input())
for _ in range(n):
	a, b = map(int, input().split(' '))
	ans = int(1)
	if a > b:
		ans = a - b
	else:
		ans = b - a
	if ans % 8 == 7 or ans % 8 == 0 or ans % 8 == 1:
		print("Farael")
	else:
		print("Ziya")
