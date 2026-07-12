/*
 * Problem Name: Money_Sums
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-07-12
 */

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int n ;
    cin>>n;
    cin>>ws;
    vector<int> arr(n+1,0);
    int total = 0;
    for(int i = 1 ; i <= n ; i++){
        cin>>arr[i];
        total += arr[i];
    }
 
    vector<vector<bool>> dp(n+1,vector<bool>(total+1,0));
    dp[0][0] = 1;
 
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= total ; j++){
            dp[i][j] = dp[i-1][j];
            if (j >= arr[i]){
                dp[i][j]  = dp[i][j] || dp[i-1][j-arr[i]];  
            }
        }
    }
 
    int ans = 0 ;
    for(int i = 1 ; i <= total ; i++){
        if (dp[n][i]) ans++;
    }
    cout<<ans<<"\n";
    for(int i = 1 ; i <= total ; i++){
        if (dp[n][i]) cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}