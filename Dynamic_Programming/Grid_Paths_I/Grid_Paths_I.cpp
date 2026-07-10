/*
 * Problem Name: Grid_Paths_I
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-07-10
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n ;
    cin >> n ;
    cin >> ws;
    vector<string> grid(n);
    for(int i = 0 ; i < n ; ++i) getline(cin,grid[i]) ;
    vector<ll> dp(n,0);
    if (grid[0][0] != '*') dp[0] = 1 ;
    ll mod = 1e9 + 7 ;
    for(int i = 0; i <n ; i ++){
        for (int j = 0; j < n ; j++){
            if (grid[i][j] == '*'){
                dp[j] = 0;
            }
            else {
                if (j != 0 ) dp[j] = (dp[j]%mod + dp[j-1] % mod) ; 
            }
        }
    }
    cout<< dp[n-1]%mod;
    return 0;
}