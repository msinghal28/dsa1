#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void bfs(int start , vector<vector<int>> &arr){
    int n = arr.size();
    vector<bool> visited(n,false);
    queue<int> q;

    visited[start] = true ;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<< node << "...";
        for(int neighbour : arr[node] ){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}



int main(){
    int n = 11;
    vector<vector<int>> arr(n);
    
    arr[1] = {3};
    arr[2] = {4};
    arr[3] = {5};
    arr[0] = {1, 2};
    arr[4] = {5};
    arr[5] = {6};
    
 
  

    cout << "BFS: ";
    bfs(0, arr);
    return 0;

}