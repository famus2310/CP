s = input()
t = int(s.count('T'))
c = int(s.count('C'))
g = int(s.count('G'))
flag = t > 0 and g > 0 and c > 0
sum = min(t, c, g)
print(t ** 2 + c ** 2 + g ** 2 + sum * 7)