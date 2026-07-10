/*
 * Problem Name: Counting_Towers
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-07-10
 */

#include <bits/stdc++.h>
using namespace std;
 
using ll = long long ;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
 
    ll mod = 1e9 + 7;
    ll m = 1e6 ;
 
    vector<vector<ll>> dp(m+1,vector<ll>(2,0));
    dp[1][0] = 1 ;
    dp[1][1] = 1 ;
 
    for (ll i = 2 ; i <= m ; i++){
        dp[i][0] = (4*dp[i-1][0] + dp[i-1][1]) % mod;
        dp[i][1] = (2*dp[i-1][1] + dp[i-1][0]) % mod;
    }
 
    ll n;
    cin >> n ;
    for(ll i = 0 ; i < n ; i ++){
        ll x;
        cin >> x ;
        cout<< (dp[x][0] + dp[x][1]) % mod <<"\n";
    }
    return 0;
 
 
 
 
}