#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Cell {
    int cost, x, y;
    bool operator>(const Cell &o) const {
        return cost > o.cost;
    }
};

int main(){
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin >> grid[i][j];

    vector<vector<int>> dist(m, vector<int>(n, 1e9));

    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;

    dist[0][0] = grid[0][0];
    pq.push({grid[0][0], 0, 0});

    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};

    while(!pq.empty()){
        auto [cost,x,y] = pq.top(); pq.pop();

        if(x == m-1 && y == n-1){
            cout << cost;
            return 0;
        }

        for(int k=0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx>=0 && ny>=0 && nx<m && ny<n){
                int newCost = cost + grid[nx][ny];
                if(newCost < dist[nx][ny]){
                    dist[nx][ny] = newCost;
                    pq.push({newCost, nx, ny});
                }
            }
        }
    }

    return 0;
}
