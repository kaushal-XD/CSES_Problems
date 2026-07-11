/*
 * Problem Name: Minimal_Grid_Path
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-07-11
 */

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n ;
    cin>>n;
    vector<string> grid(n);
    for (int i = 0 ; i < n ; i++) cin>>grid[i];
 
    string ans = "";
    ans += grid[0][0];
 
    vector<pair<int,int>> active;
    active.push_back({0,0});
 
    vector<vector<bool>> check(n,vector<bool>(n,0));
    check[0][0] = 1;
 
    for(int step = 0 ; step < 2*n-2 ; step++){
        char min_c = 'Z'+1;
        vector<pair<int,int>> next;
 
        for (auto p : active){
            int r = p.first;
            int c = p.second;
 
            if (c+1 < n && !check[r][c+1]){
                if (grid[r][c+1]<min_c){
                    min_c = grid[r][c+1];
                    next.clear();
                    next.push_back({r,c+1});
                    check[r][c+1] = 1;
                }
                else if (grid[r][c+1] == min_c){
                    next.push_back({r,c+1});
                    check[r][c+1] = 1;
                }
            }
 
            if (r+1 < n && !check[r+1][c]){
                if (grid[r+1][c] < min_c){
                    min_c = grid[r+1][c];
                    next.clear();
                    next.push_back({r+1,c});
                    check[r+1][c] = 1 ;
                }
                else if (grid[r+1][c] == min_c) {
                    next.push_back({r+1,c});
                    check[r+1][c] = 1;
 
                }
            }
        }
        ans += min_c;
        active = next;
 
    }
    cout<<ans<<endl;
    return 0;
 
}