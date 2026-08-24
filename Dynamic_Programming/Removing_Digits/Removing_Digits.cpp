/*
 * Problem Name: Removing_Digits
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-08-24
 */

#include <bits/stdc++.h>
using namespace std;
 
int rec(int n, vector<int>& dp){
    if (n == 0) return 0;
    if (n < 0) return 1e9;
    if (dp[n] != -1) return dp[n];
    int temp = n;
    int ans = 1e9;
    while(temp){
        int r = temp % 10;
        temp /= 10;
        if (r != 0) ans = min(ans,rec(n-r ,dp)+1);
    }
    dp[n] = ans;
    return ans;
}
 
 
int main() {
    int n; 
    cin>>n;
    vector<int> dp(n+1,-1);
	cout<<rec(n,dp);
	return 0;
 
}