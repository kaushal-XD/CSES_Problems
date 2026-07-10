/*
 * Problem Name: Longest_Common_Subsequence
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-07-10
 */

#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int n , m ;
    cin>>n>>m;
    vector<int> arr1(n,0);
    vector<int> arr2(m,0);
    for(int i = 0 ; i < n ; i++) cin >> arr1[i];
    for(int i = 0 ; i < m ; i++) cin >> arr2[i];
 
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
 
    for(int i = 1 ; i < n+1 ; i++){
        for(int j = 1 ; j < m+1 ; j++){
            if (arr1[i-1] == arr2[j-1]) dp[i][j] = dp[i-1][j-1] +1 ;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
 
    int i = n;
    int j = m;
    int check = dp[n][m];
    vector<int> ans(check,0);
    while(i>0 && j > 0 ) {
        if (arr1[i-1] == arr2[j-1]){
            check--;
            ans[check] = arr1[i-1];
            i--;j--;
        }
        else {
            if (dp[i-1][j] < dp[i][j-1]) j--;
            else i--;
        }
    }
    cout<<dp[n][m]<<endl;
    for(int i = 0 ; i < dp[n][m] ; i++) cout<<ans[i]<<" ";
 
    return 0;
}