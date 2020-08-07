# Python implementation of the above approach 
 
# function to return count of distinct bitwise OR 
def subarrayBitwiseOR(A): 
 
	# res contains distinct values 
	res = set() 
	pre = {0} 
	for x in A:

		pre = {x | y for y in pre} | {x} 
		res |= pre 
	return len(res) 
 
 
# Driver program 
t = int(input())
 
for j in range(t):
	n = int(input())
	x = input()
	A = list(map(int, x.split(' ')))
	print(subarrayBitwiseOR(A)) 
 
# This code is written by 
# Sanjit_Prasad 