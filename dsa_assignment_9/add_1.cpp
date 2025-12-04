#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis){
    vis[node] = 1;
    for(int nxt : adj[node])
        if(!vis[nxt]) dfs(nxt, adj, vis);
}

int main(){
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];
    for(int i=0;i<E;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(V, 0);
    int components = 0;

    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i, adj, vis);
            components++;
        }
    }

    cout << components;
    return 0;
}
