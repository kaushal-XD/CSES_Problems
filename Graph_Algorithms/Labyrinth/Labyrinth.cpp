/*
 * Problem Name: Labyrinth
 * Language: C++
 * Category: Graph_Algorithms
 * Date: 2026-07-26
 */

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
typedef long long ll;
const vector<int> dr = {-1,0,1,0};
const vector<int> dc = {0,1,0,-1};
const vector<char> dir = {'U','R','D','L'};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for(int i = 0 ; i< n ; i++ ) cin>>grid[i];
 
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    vector<vector<char>> premove(n,vector<char>(m,0));
    pii start;
    pii end;
 
    for(int j = 0 ; j < n ; j++){
        for(int i = 0 ; i < m ; i++){
            if (grid[j][i] == 'A') {
                start = {j,i};
            }
            else if (grid[j][i] == 'B'){
                end = {j,i};
            }
        }
    }
 
    queue<pii> q;
    q.push(start);
    bool check = false;
    visited[start.first][start.second] = true;
 
    while(!check && !q.empty()){
        pii cur = q.front();
        q.pop();
        for(int d = 0 ; d < 4 ; d++){
            int nr = dr[d] + cur.first;
            int nc = dc[d] + cur.second;
 
            if(nr >= 0 && nc >= 0 && nr < n && nc < m && !visited[nr][nc] && grid[nr][nc] != '#'){
                visited[nr][nc] = true;
                q.push({nr,nc});
                premove[nr][nc] = dir[d];
            }
 
            if (make_pair(nr,nc) == end){
                check = true;
                break;
            }
        }
    }
    if (check){
        pii temp = end;
        stack<char> st;
        while (temp != start){
            int nr = temp.first ;
            int nc = temp.second ;
            char c = premove[nr][nc] ;
            st.push(c);
            int d = find(dir.begin(),dir.end(),c) - dir.begin();
            nr -= dr[d];
            nc -= dc[d];
            temp = {nr,nc};
        }
        cout<<"YES\n"<<st.size()<<endl;
        while(!st.empty()){
            cout<<st.top();
            st.pop();
        }
        cout<<endl;
    }
 
    else cout<<"NO"<<"\n";
 
 
    return 0;
}