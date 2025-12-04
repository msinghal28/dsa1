#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Edge {
    int node, wt;
};

struct State {
    int dist, node;
    bool operator>(const State &o) const {
        return dist > o.dist;
    }
};

int main(){
    int N, E, K;
    cin >> N >> K >> E;

    vector<vector<Edge>> adj(N+1);
    for(int i=0;i<E;i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> dist(N+1, 1e9);
    priority_queue<State, vector<State>, greater<State>> pq;

    dist[K] = 0;
    pq.push({0, K});

    while(!pq.empty()){
        auto [d, node] = pq.top(); pq.pop();

        for(auto &e : adj[node]){
            int nd = d + e.wt;
            if(nd < dist[e.node]){
                dist[e.node] = nd;
                pq.push({nd, e.node});
            }
        }
    }

    int ans = 0;
    for(int i=1;i<=N;i++){
        if(dist[i] == 1e9){
            cout << -1;
            return 0;
        }
        ans = max(ans, dist[i]);
    }

    cout << ans;
    return 0;
}
