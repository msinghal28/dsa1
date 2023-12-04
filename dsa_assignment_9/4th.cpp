#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n = 6;
    vector<vector<pair<int,int>>> g(n);

    g[1].push_back({2,3});
    g[2].push_back({1,3});
    g[1].push_back({3,1});
    g[3].push_back({1,1});
    g[2].push_back({4,4});
    g[4].push_back({2,4});
    g[3].push_back({4,2});
    g[4].push_back({3,2});
    g[3].push_back({5,6});
    g[5].push_back({3,6});

    vector<bool> vis(n,false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    int total = 0;

    while(!pq.empty()){
        auto p = pq.top(); pq.pop();
        int w=p.first, node=p.second;
        if(vis[node]) continue;
        vis[node]=true;
        total += w;

        for(auto &x: g[node]){
            pq.push({x.second, x.first});
        }
    }

    cout << total;
}
