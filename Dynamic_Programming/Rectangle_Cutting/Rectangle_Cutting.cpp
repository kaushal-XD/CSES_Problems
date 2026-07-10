/*
 * Problem Name: Rectangle_Cutting
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-07-10
 */

#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n , m ;
    cin>>n >> m ;
 
    vector<vector<int>> dp(n+1,vector<int>(m+1,1e9));
 
    for (int i = 1; i < n+1 ; i++){
        for (int j = 1 ; j < m+1 ; j++){
            if (i == j ) dp[i][j] = 0 ; 
 
            else {
                for(int v = 1 ; v <= i-1 ; v++){
                    dp[i][j] = max(dp[i][j],dp[j-v][j] + dp[v][j] + 1);
                }
                for(int h = 1 ; h <= j-1 ; h++){
                    dp[i][j] = max(dp[i][j],dp[i][h] + dp[i][j-h] + 1);
                }
 
            }
        
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
 
}