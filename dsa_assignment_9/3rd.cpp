#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU{
public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void unite(int a,int b){
        a=find(a); b=find(b);
        if(a!=b){
            if(size[a]<size[b]) swap(a,b);
            parent[b]=a;
            size[a]+=size[b];
        }
    }
};

int main(){
    int n = 6;
    vector<vector<int>> edges = {
        {1, 2, 3},
        {1, 3, 1},
        {2, 4, 4},
        {3, 4, 2},
        {3, 5, 6}
    };

    sort(edges.begin(), edges.end(), [](auto &a, auto &b){
        return a[2] < b[2];
    });

    DSU d(n+1);
    int total = 0;

    for(auto &e : edges){
        int u=e[0], v=e[1], w=e[2];
        if(d.find(u)!=d.find(v)){
            d.unite(u,v);
            total += w;
        }
    }

    cout << total;
}
