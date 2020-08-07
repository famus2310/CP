import math	

def modex(a, b):
	ret = 1
	while b > 0:
		if (b & 1):
			ret = (ret * a) % 1000000007
		b = b >> 1
		a = (a**2) % 1000000007
	return ret

def func(n, m):
	if (n == 1 or n == 2):
		return m
	return (modex(2, n - 2) * (m % 1000000007)) % 1000000007

def solve(n):
	ret = -1
	while n % 2 == 0:
		ret = 2
		n = n >> 1
	for i in range(3, int(math.sqrt(n)) + 1, 2):
		while n % i == 0:
			ret = i
			n //= i
		if (n == 1):	
			break
	if n > 1:
		ret = max(ret, n)
	return ret



t, m = map(int, input().split())
ans = 0
for i in range(t):
	n = int(input())
	f = func(n, m)
	c = solve(f + n % 1000000007 + m % 1000000007) % 1000000007
	ans += c
print("The President needs to pay %d dollar(s)" % ans)
