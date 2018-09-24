def swap(a, b):
	a, b = b, a
	return a, b

n = int(input())
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]
q = int(input())
for i in range(q):
	s = input().split()
	if (s[0] == "A") and (s[2] == "B"):
		A[int(s[1]) - 1], B[int(s[3]) - 1] = swap(A[int(s[1]) - 1], B[int(s[3]) - 1])
	elif (s[0] == "B") and (s[2] == "A"):
		B[int(s[1]) - 1], A[int(s[3]) - 1] = swap(B[int(s[1]) - 1], A[int(s[3]) - 1])
	elif (s[0] == "A") and (s[2] == "A"):
		A[int(s[1]) - 1], A[int(s[3]) - 1] = swap(A[int(s[1]) - 1], A[int(s[3]) - 1])
	else:
		B[int(s[1]) - 1], B[int(s[3]) - 1] = swap(B[int(s[1]) - 1], B[int(s[3]) - 1])
for i in range(len(A)):
	if (i != 0):
		print(" ", end = "")
	print(A[i], end = "")
print("")
for i in range(len(B)):
	if (i != 0):
		print(" ", end = "")
	print(B[i], end = "")
print("")