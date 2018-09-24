row = []
for i in range(3):
	col = input().split()
	row.append(col)
for i in range(3):
	for j in range(3):
		if (j != 0):
			print(" ", end = "")
		print(row[j][i], end = "")
	print("")