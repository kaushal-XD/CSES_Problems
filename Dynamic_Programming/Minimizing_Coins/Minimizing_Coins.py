# Problem Name: Minimizing_Coins
# Language: Python
# Category: Dynamic_Programming
# Date: 2026-07-10

import sys
"""
def func(x,coins):
    if x == 0 :
        return 0
    if x < 0 :
        return float("inf")
    ans = float("inf")
    for num in coins:
        ans = min(ans,func(x-num,coins)+1)
 
    return ans
"""
"""
data = map(int,sys.stdin.read().split())
n = next(data)
x = next(data)
coins = [next(data) for _ in range(n)]
"""
import sys
 
data = sys.stdin.read().split()
n = int(data[0])
x = int(data[1])
coins = [int(data[i]) for i in range(2,n+2)]
inf = x +1 
dp = [inf]*(x+1)
dp[0] = 0
for c in coins :
    for i in range(c,x+1):
        if dp[i-c]+1 < dp[i] :
            dp[i] = dp[i-c]+1
 
print( dp[x] if dp[x] != inf else -1 )
 