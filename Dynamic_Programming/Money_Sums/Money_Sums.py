# Problem Name: Money_Sums
# Language: Python
# Category: Dynamic_Programming
# Date: 2026-07-12

import sys
 
data = sys.stdin.read().split()
 
n = int(data[0])
ar = [int(x) for x in data[1:]]
t = sum(ar)
dp = [False]*(t+1)
dp[0] = True
for a in ar :
    for i in range(t,a-1,-1):
        if dp[i-a]:
            dp[i] = True
o = [i for i in range(i,t+1) if dp[i] ]
print(len(o))
print(*o)