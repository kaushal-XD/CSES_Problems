/*
 * Problem Name: Building_Teams
 * Language: C++
 * Category: Graph_Algorithms
 * Date: 2026-07-26
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> adj;
vector<int> visited;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    visited.assign(n+1,-1);
 
    for(int i = 0 ; i < m ; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1 ; i <= n ; i++){
        if (visited[i] != -1) continue;
        queue<int> q;
        q.push(i);
        visited[i] = 1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int nxt : adj[cur]){
                if (visited[cur] == visited[nxt]){
                    cout<<"IMPOSSIBLE"<<endl;
                    return 0;
                }
                if (visited[nxt] == -1){
                    q.push(nxt);
                    if (visited[cur] == 1) visited[nxt] = 2;
                    else visited[nxt] = 1;
                }
            }
        }
    }
    for(int i = 1 ; i <= n ; i++){
        cout<<visited[i]<<" ";
    }
 
    cout<<endl;
 
    return 0;
}