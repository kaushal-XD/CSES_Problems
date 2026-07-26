/*
 * Problem Name: Message_Route
 * Language: C++
 * Category: Graph_Algorithms
 * Date: 2026-07-26
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> adj;
vector<bool> visited;
 
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
 
    vector<int> parent(n+1,-1);
 
    bool check = false;
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty() && !check){
        int cur = q.front();
        q.pop();
        for(int nxt : adj[cur]){
            if (!visited[nxt]){
                q.push(nxt);
                parent[nxt] = cur;
                visited[nxt] = true;
            }
            if (nxt == n){
                check = true;
                break;
            }
 
        }
    }
    if (!check){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
 
    stack<int> st;
    int curr = n;
    st.push(curr);
    while(curr != -1 ){
        curr = parent[curr];
        st.push(curr);
    }
    st.pop();
    cout<<st.size()<<endl;
    while (!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
 
 
    return 0;
}