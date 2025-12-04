#include<iostream>
#include<vector>
using namespace std;

void dfs(int x, int y, vector<vector<char>> &grid, int m, int n){
    if(x<0 || y<0 || x>=m || y>=n || grid[x][y]=='0') return;

    grid[x][y] = '0';

    dfs(x+1,y,grid,m,n);
    dfs(x-1,y,grid,m,n);
    dfs(x,y+1,grid,m,n);
    dfs(x,y-1,grid,m,n);
}

int main(){
    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin >> grid[i][j];

    int count = 0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == '1'){
                count++;
                dfs(i,j,grid,m,n);
            }
        }
    }

    cout << count;
    return 0;
}
