import time

def output(s) :
	tmplist = list(s)
	for i in range(3) :
		for j in range(3) :
			print(tmplist[i * 3 + j], end = " ")
		print()
	print()

def swap(s, i, j) :
	tmplist = list(s)
	tmplist[i], tmplist[j] = tmplist[j], tmplist[i]
	return ''.join(tmplist)

progstart = time.time()
print("|---------------------------------------------|")
print("| Running 8-Puzzle Solver Using BFS Algorithm |")
print("|---------------------------------------------|")
now = input("Input Initial State : ")
target = input("Input Goal State : ")

start = time.time()
zero = 0
for i in range(len(now)) :
	if now[i] == '0' :
		zero = i

q = []
q.append([now, zero])
vis = []
vis.append(now)
par = {now : "-1"}

trial = 0
while q :
	trial = trial + 1
	s = q.pop(0)
	tmp = s[0]
	if s[0] == target:
		break
	if s[1] < 6 :
		s[0] = swap(s[0], s[1], s[1] + 3);
		if s[0] not in vis :
			q.append([s[0], s[1] + 3])
			vis.append(s[0])
			par[s[0]] = tmp
		s[0] = swap(s[0], s[1], s[1] + 3);

	if (s[1] > 2) :
		s[0] = swap(s[0], s[1], s[1] - 3)
		if s[0] not in vis :
			q.append([s[0], s[1] - 3])
			vis.append(s[0])
			par[s[0]] = tmp
		s[0] = swap(s[0], s[1], s[1] - 3)

	if (s[1] % 3 != 0) :
		s[0] = swap(s[0], s[1], s[1] - 1)
		if s[0] not in vis :
			q.append([s[0], s[1] - 1])
			vis.append(s[0])
			par[s[0]] = tmp
		s[0] = swap(s[0], s[1], s[1] - 1)

	if (s[1] % 3 != 2) :
		s[0] = swap(s[0], s[1], s[1] + 1)
		if s[0] not in vis :
			q.append([s[0], s[1] + 1])
			vis.append(s[0])
			par[s[0]] = tmp
		s[0] = swap(s[0], s[1], s[1] + 1)

finish = time.time()
ans = []
step = 0
while target != now :
	# print(target)
	ans.append(target)
	target = par[target]
	step = step + 1
ans.append(now)

print("STEPS :")
ans.reverse()
for i in ans :
	output(i)

print("Number of trial =",trial)
print("Number of step =",step)
print("Total processing time (without I/O) =","%0.10f" % (finish - start), "second(s)")
progend = time.time()
print("Total program running time =", "%.10f" % (progend - progstart), "second(s)")
# print(ans)
