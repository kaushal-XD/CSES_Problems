/*
 * Problem Name: Round_Trip
 * Language: C++
 * Category: Graph_Algorithms
 * Date: 2026-07-26
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;
int n,m;
int start  = -1;
int c_end ;
 
 
bool dfs(int node , int prt){
    visited[node] = true;
    for(int nxt : adj[node]){
        if (nxt == prt ) continue;
 
        if (visited[nxt]){
            start = nxt;
            c_end = node;
            return true;
        }
        else {
            parent[nxt] = node;
            if(dfs(nxt,node)) return true;
        }
    }
    return false;
}
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    visited.assign(n+1,false);
    parent.assign(n+1,-1);
 
    for(int i = 0 ; i < m ; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    for(int i = 1 ; i <= n ; i++){
        if (!visited[i] && dfs(i,-1)) break;
    }
 
    if (start == -1){
        cout<<"IMPOSSIBLE"<<"\n";
        return 0;
    }
 
    int curr = c_end;
    vector<int> ans;
    ans.push_back(start);
    while(curr != start){
        ans.push_back(curr);
        curr = parent[curr];
    }
    ans.push_back(start);
 
    cout<<ans.size()<<endl;
    for(int i : ans){
        cout<<i<<" ";
    }
 
    return 0;
}