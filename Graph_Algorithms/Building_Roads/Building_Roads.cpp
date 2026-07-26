/*
 * Problem Name: Building_Roads
 * Language: C++
 * Category: Graph_Algorithms
 * Date: 2026-07-26
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> adj;
vector<bool> visited;
 
 
void dfs( int u){
    visited[u] = true;
    for(int v : adj[u]){
        if (!visited[v]){
            dfs(v);
        }
    }
}
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    visited.assign(n+1,false);
 
    for(int i = 0 ; i < m ; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> leads;
    for(int i = 1 ; i <= n ; i++){
        if (!visited[i]){
            leads.push_back(i);
            dfs(i);
        }
    }
 
    int k = leads.size()-1;
    cout<<k<<"\n";
    for(int i = 0 ; i < k ; i++){
        cout<<leads[i]<<" "<<leads[i+1]<<"\n";
    }
    return 0;
}