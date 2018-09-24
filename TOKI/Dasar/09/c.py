arr = [0] * 1005
n = int(input())
inp = [int(x) for x in input().split()]
for i in inp:
	arr[i] += 1
ans, now = -1, -1
for i in range(1, len(arr)):
	if arr[i] >= now:
		ans = i
		now = arr[i]
print(ans)
