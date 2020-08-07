n, m, p = map(int, input().split())
matrix1 = []
matrix2 = []
ans = []
for i in range(n):
	col = [int(x) for x in input().split()]
	matrix1.append(col)
for i in range(m):
	col = [int(x) for x in input().split()]
	matrix2.append(col)
for i in range(n):
	col = []
	for j in range(p):
		now = 0
		for k in range(m):
			now += matrix1[i][k] * matrix2[k][j]
		col.append(now)
	ans.append(col)
for i in range(n):
	for j in range(p):
		if (j != 0):
			print(" ", end = "")
		print(ans[i][j], end = "")
	print("")