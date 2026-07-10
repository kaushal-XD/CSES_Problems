# Problem Name: Dice_Combinations
# Language: Python
# Category: Dynamic_Programming
# Date: 2026-07-10

from functools import lru_cache 
 
n = 1000
"""
# using recursion and cache memory
@lru_cache(maxsize = 1000)
def dicesum(n):
    if n == 0 :
        return 1
    if n < 0 :
        return 0
    ans = 0
    for i in range(1,6):
        ans += dicesum(n-i)
 
    return ans
 
print(dicesum(n))
"""
"""
# using bottoms up approch 
def funcbu(n,dp):
 
    if dp[n] != -1:
        return dp[n]
    ans = 0
    for i in range(1,6):
        if n-i >= 0 :
            ans += funcbu(n-i,dp)
    
    dp[n] = ans
    return ans
 
n = 100
dp = [-1]*(n+1)
dp[0] = 1
 
print(funcbu(n,dp))
 
"""
 
# top Down Appproch 
def topdown(n):
    mod = 10**9 + 7 
    dp = [0] * (n+1)
    dp[0] = 1
    for i in range(1,n+1):
        ans = 0
        for j in range(max(0,i-6),i):
            ans = (ans%mod + dp[j]%mod)%mod
 
        dp[i] = ans
    return dp[n]
n = int(input())
print(topdown(n))