/*
 * Problem Name: Array_Description
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-07-10
 */

#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n , m ;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i ++) cin >> arr[i];
 
    vector<vector<int>> dp(n,vector<int>(m+2,0));
 
    if (arr[0] == 0 ){
        for(int i = 1 ; i <= m; i++) dp[0][i] = 1 ;
    }
    else dp[0][arr[0]] = 1;
    int mod = 1e9 + 7 ;
 
    for(int i = 1 ; i < n ; i++){
        if (arr[i] == 0 ){
        for (int j = 1 ; j <= m ; j++ ){
            dp[i][j] = dp[i-1][j] ;
            if (j-1 >= 1) dp[i][j] = (dp[i][j] + dp[i-1][j-1])%mod ;
            if (j+1 <= m) dp[i][j] = ( dp[i][j] + dp[i-1][j+1])%mod ;
        }}
        else {
            int j = arr[i] ;
            dp[i][j] = dp[i-1][j] ;
            if (j-1 >= 1) dp[i][j] = (dp[i][j] + dp[i-1][j-1])%mod ;
            if (j+1 <= m) dp[i][j] = (dp[i][j] + dp[i-1][j+1])%mod ;
 
        }
    }
    
    int ans = 0;
    for(int i = 1 ; i <= m ; i ++) ans = (ans + dp[n-1][i])%mod ;
    cout<<ans<<"\n";
 
    return 0;
}