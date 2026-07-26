/*
 * Problem Name: Counting_Rooms
 * Language: C++
 * Category: Graph_Algorithms
 * Date: 2026-07-26
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
void solve(int n, int m, vector<string>& grid){
    const int dr[] = {1,0,-1,0};
    const int dc[] = {0,1,0,-1};
 
    vector<vector<bool>> check(n,vector<bool>(m,0));
    deque<pair<int,int>> dq;
    int ans = 0 ;
 
    for(int r = 0 ; r < n ; r++){
        for(int c = 0 ; c < m ; c++){
            if (grid[r][c] == '.' && !check[r][c]){
                dq.push_back({r,c});
                check[r][c] = 1;
                ans++;
 
                while(!dq.empty()){
                    auto cur = dq.front();
                    dq.pop_front();
                    int x = cur.first;
                    int y = cur.second;
                    for(int i = 0; i < 4 ; i++){
                        int nr = x + dr[i];
                        int nc = y + dc[i];
                        if (nr < n && nc < m && nr>= 0 && nc >= 0 && grid[nr][nc] == '.' && !check[nr][nc]){
                            check[nr][nc] = 1;
                            dq.push_back({nr,nc});
                        }
                    }
                }
            }
        }
    }
 
    cout<<ans<<endl;
    return;
}
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for(int i = 0 ; i < n ; i++){
        cin>>grid[i];
    }
 
    solve(n,m,grid);
    return 0;
}