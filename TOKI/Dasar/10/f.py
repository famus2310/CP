import math
def T(xj, xi, yj, yi, D):
	return int(math.fabs(xj - xi)) ** D + int(math.fabs(yj - yi)) ** D

N, D = map(int, input().split())
arr = []
ans = []
for i in range(N):
	col = [int(x) for x in input().split()]
	arr.append(col)
for i in range(N):
	for j in range(i + 1, N):
		ans.append(T(arr[i][0], arr[j][0], arr[i][1], arr[j][1], D))
mx = max(ans)
mn = min(ans)
print(mn, mx)