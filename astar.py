import time
import heapq

def manhattan(s1, s2) :
	tmplist1 = [None] * 15
	tmplist2 = [None] * 15
	for i in range(9) :
		# print(int(s1[i]))
		tmplist1[int(s1[i])] = [i // 3, i % 3]
		tmplist2[int(s2[i])] = [i // 3, i % 3]

	ret = 0
	for i in range(9) :
		ret = ret + abs(tmplist1[i][0] - tmplist2[i][0]) + abs(tmplist1[i][1] - tmplist2[i][1])
	return ret

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
print("|------------------------------------------------------------------------------------------|")
print("| Running 8-Puzzle Solver Using A* Algorithm with Manhattan Distance as Heuristic Function |")
print("|------------------------------------------------------------------------------------------|")
now = input("Input Initial State : ")
target = input("Input Goal State : ")

start = time.time()
zero = 0
for i in range(len(now)) :
	if now[i] == '0' :
		zero = i

vis = {}
vis[now] = 0
q = []
heapq.heapify(q)
par = {now : "-1"}
heapq.heappush(q, (vis[now] + manhattan(now, target), now, zero))

trial = 0
while q :
	trial = trial + 1
	s = heapq.heappop(q)
	tmp = s[1]
	tmps1 = s[1]
	zeropos = s[2]
	if tmps1 == target:
		break
	if zeropos < 6 :
		tmps1 = swap(tmps1, zeropos, zeropos + 3)
		if (tmps1 not in vis) or vis[tmps1] > vis[tmp] + 1 :
			vis[tmps1] = vis[tmp] + 1
			par[tmps1] = tmp
			heapq.heappush(q, (vis[tmps1] + manhattan(tmps1, target), tmps1, zeropos + 3))
		tmps1 = swap(tmps1, zeropos, zeropos + 3);

	if (zeropos > 2) :
		tmps1 = swap(tmps1, zeropos, zeropos - 3)
		if tmps1 not in vis or vis[tmps1] > vis[tmp] + 1:
			vis[tmps1] = vis[tmp] + 1
			par[tmps1] = tmp
			heapq.heappush(q, (vis[tmps1] + manhattan(tmps1, target), tmps1, zeropos - 3))
		tmps1 = swap(tmps1, zeropos, zeropos - 3)

	if (zeropos % 3 != 0) :
		tmps1 = swap(tmps1, zeropos, zeropos - 1)
		if tmps1 not in vis or vis[tmps1] > vis[tmp] + 1:
			vis[tmps1] = vis[tmp] + 1
			par[tmps1] = tmp
			heapq.heappush(q, (vis[tmps1] + manhattan(tmps1, target), tmps1, zeropos - 1))
		tmps1 = swap(tmps1, zeropos, zeropos - 1)

	if (zeropos % 3 != 2) :
		tmps1 = swap(tmps1, zeropos, zeropos + 1)
		if tmps1 not in vis or vis[tmps1] > vis[tmp] + 1:
			vis[tmps1] = vis[tmp] + 1
			par[tmps1] = tmp
			heapq.heappush(q, (vis[tmps1] + manhattan(tmps1, target), tmps1, zeropos + 1))
		tmps1 = swap(tmps1, zeropos, zeropos + 1)

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
