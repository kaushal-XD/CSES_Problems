/*
 * Problem Name: Two_Sets_II
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-07-15
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7 ;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
 
    ll n;
    cin>> n;
 
    ll total = n*(n+1)*0.5 ;
    if (total & 1){
        cout<<0<<"\n";
        return 0;
    }
    ll x = total/2;
    vector<ll> dp(x+1,0);
    dp[0] = 1;
 
    for(int i = 1; i <= n ; i++){
        for(int j = x ; j >= i ; j--){
            dp[j] = (dp[j] + dp[j-i])%mod;
        }
    }
    cout<<(dp[x]*500000004)%mod;
    return 0;
}