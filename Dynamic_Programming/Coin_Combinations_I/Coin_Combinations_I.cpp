/*
 * Problem Name: Coin_Combinations_I
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-07-10
 */

#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
 
    int n,x;
    
    cin>>n>>x;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i ++) {
        cin >> arr[i];
    }
    int mod = 1e9 + 7;
 
    vector<int> dp(x+1,0);
    dp[0] = 1;
    for(int i = 1; i < x+1; i++){
        for (int c : arr){
            if (i-c >= 0) 
                dp[i] = (dp[i] + dp[i-c])%mod;
        }
    }
    cout<<dp[x]<<"\n";
    return 0;
}