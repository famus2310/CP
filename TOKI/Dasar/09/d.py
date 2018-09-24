n, m = map(int, input().split())
matrix = []
for i in range(n):
	col = [int(x) for x in input().split()]
	matrix.append(col)
for i in range(m):
	for j in range(n - 1, -1, -1):
		if (j != n - 1):
			print(" ", end = "")
		print(matrix[j][i], end = "")
	print("")
