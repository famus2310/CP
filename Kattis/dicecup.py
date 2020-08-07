n, m = map(int, input().split())
arr = [0] * 55
mx = -1
for i in range(1, n + 1):
	for j in range(1, m + 1):
		arr[i + j] += 1
		mx = max(mx, arr[i + j])
for i in range(1, 55):
	if (arr[i] == mx):
		print(i)