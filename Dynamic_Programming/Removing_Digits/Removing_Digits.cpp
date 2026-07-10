/*
 * Problem Name: Removing_Digits
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-07-10
 */

#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, num;
    cin >> n ;
    vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <n+1 ; i++ ){
        num = i;
        while(num>0){
            int d = num%10;
            if (d){
                dp[i] = min(dp[i],dp[i-d]+1);
            }
            num = num/10;
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}