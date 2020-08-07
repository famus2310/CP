def rev(x):
	ret = 0
	while (x > 0):
		ret = ret * 10 + x % 10
		x //= 10
	return ret

a, b = map(int, input().split())
temp = rev(a) + rev(b)
temp = rev(temp)
print(temp)