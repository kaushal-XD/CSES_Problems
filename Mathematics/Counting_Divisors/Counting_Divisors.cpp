/*
 * Problem Name: Counting_Divisors
 * Language: C++
 * Category: Mathematics
 * Date: 2026-09-14
 */

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    for(int jk = 0 ; jk < t ; jk++){
        int n ;
        cin>>n;
        long long ans = 1;
        for(int i = 2 ; i*i <= n ; i++){
            int cnt = 0;
            while(n%i == 0){
                n/= i;
                cnt++;
            }
            ans *= (cnt +1);
        }
        if (n > 1) ans *= 2;
        cout<<ans<<endl;
    }
    
    return 0;
 
}