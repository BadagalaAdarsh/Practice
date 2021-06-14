#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

void dfs(vector<vector<int>>& grid, int i, int j, int row, int col) {
        
    if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] != 1) {
        return ;
    }
    grid[i][j] = 2; // assuming 2 as visited

    dfs(grid, i-1,j,row,col);
    dfs(grid,i+1,j,row,col);
    dfs(grid, i, j+1, row,col);
    dfs(grid,i,j-1,row,col);
}

int numberOfIsland(vector<vector<int>>& grid) {

    int row = grid.size();
    if (row == 0){
        return 0;
    }
    int col = grid[0].size();

    int answer  = 0;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if (grid[i][j] == 1){
                answer++;
                dfs(grid,i,j,row, col);
            }
        }
    }
    return answer;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;

    while(test--) {

        int row,col;
        cin >> row >> col;

        vector<vector<int>> grid(row, vector<int>(col));

        for(int i = 0; i < row; i++){
            for(int j = 0; i < col; j++){
                cin >> grid[i][j];
            }
        }

        cout << numberOfIsland(grid) << endl;
    }
}