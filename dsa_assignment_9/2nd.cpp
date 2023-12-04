#include <iostream>
#include <vector>
using namespace std;

void dfsUtil(int node, vector<vector<int>> &arr, vector<bool> &vis){
    vis[node] = true;
    cout << node << "...";
    for(int x : arr[node]){
        if(!vis[x]){
            dfsUtil(x, arr, vis);
        }
    }
}

void dfs(int start, vector<vector<int>> &arr){
    int n = arr.size();
    vector<bool> vis(n, false);
    dfsUtil(start, arr, vis);
}

int main(){
    int n = 11;
    vector<vector<int>> arr(n);

    arr[1]={3};
    arr[2]={4};
    arr[3]={5};
    arr[0]={1,2};
    arr[4]={5};
    arr[5]={6};

    dfs(0, arr);
}
