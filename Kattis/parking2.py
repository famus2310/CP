t = int(input())
for tc in range(t):
	n = int(input())
	arr = [int(x) for x in input().split()]
	mx = max(arr)
	mn = min(arr)
	print(int(mx - mn) * 2)