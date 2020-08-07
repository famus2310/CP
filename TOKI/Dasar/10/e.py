import math
def f(x, rec, A, B):
	if (rec == 1):
		return int(math.fabs(A*x + B))
	return int(math.fabs(f(x, rec - 1, A, B) * A + B))

A, B, K, x = map(int, input().split())
ans = f(x, K, A, B)
print(ans)