import math
ans = "S"
for i in range(1, 21):
   c = 'L' if math.sin(i * i) < 0 else 'K'
   ans += c
print(ans.lower())
print(len(ans))
