inp = int(input())
for i in range(1, inp + 1):
	if i == 42:
		print("ERROR")
		break
	if i % 10 != 0:
		print(i)
