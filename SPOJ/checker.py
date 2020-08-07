def b(n, t): # using length as an argument
    t.sort()
    z = sum(t) + (n-3) * t[0] * (n>1) # just sum(t) == t[0] if len(t) == 1
    for k in range(n/2):
        z += min(0, 2*t[1] - t[0] - t[-(k+1)*2]) # ~k == -(k+1)
    return z

n = input()
print(b(n))