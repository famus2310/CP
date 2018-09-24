s1, s2 = map(str, input().split())
while (s2 in s1):
	s1 = s1.replace(s2, "")
print(s1)