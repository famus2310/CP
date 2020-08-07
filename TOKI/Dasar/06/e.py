def countSet(x):
	return bin(x).count("1")

inp = int(input())
if (countSet(inp) == 1):
	print("ya")
else:
	print("bukan")