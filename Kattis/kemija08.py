string = input()
i = 0

vowel = ["a", "i", "u", "e", "o"]

while i < len(string):
	if string[i] in vowel:
		string = string[:i] + string[i + 2:]	
	i += 1
print(string)
