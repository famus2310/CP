import math
x1, y1, x2, y2 = input().split()
print("%d" % (math.fabs(int(x1) - int(x2)) + math.fabs(int(y1) - int(y2))))	