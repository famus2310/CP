string = input()
now = 1
for i in string:
	if (now == 1):
		if i == "A":
			now = 2
		elif i == "C":
			now = 3
	elif (now == 2):
		if i == "A":
			now = 1
		elif i == "B":
			now = 3
	elif (now == 3):
		if i == "B":
			now = 2
		elif i == "C":
			now = 1
print(now)