/*
 * Problem Name: Edit_Distance
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-07-10
 */

#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
 
    string s1,s2; 
    cin>>s1>>s2;
    int n = s1.length();
    int m = s2.length();
 
    vector<vector<int>> dp(n+1,vector<int>(m+1,1000));
    for(int i = 0 ; i < n+1 ; i++) dp[i][0] = i ;
    for(int i = 0 ; i < m+1 ; i++) dp[0][i] = i ;
 
    for(int i = 1 ; i < n+1 ; i++) {
        for (int j = 1 ; j < m+1 ; j++){
            char a = s1[i-1];
            char b = s2[j-1];
 
            if (a == b) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = dp[i-1][j-1] + 1 ;
 
            dp[i][j] = min({dp[i][j-1] + 1 , dp[i-1][j] + 1 , dp[i][j]});
        }
    }
    cout<< dp[n][m] << "\n";
    return 0 ;
}