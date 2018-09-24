import math

def solve(r):
	return math.pi * r * r;

def work(r):
	return 2.0 * r * r;
r = int(input());
print(solve(r))
print(work(r))