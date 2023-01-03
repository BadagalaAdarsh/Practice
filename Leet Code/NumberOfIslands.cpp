/*
Number of Islands

Solution
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

#include<bits/stdc++.h>
using namespace std;

int numOfIslands( vector<vector<char>>& grid){

    if (grid.empty() || grid[0].empty()){
        return 0;
    }

    int H = grid.size();
    int W = grid[0].size();
    int answer = 0;

    auto inside = [&](int row , int col){
        return 0 <= row && row < H && 0 <= col && col < W;
    };

    vector<pair<int,int>> directions{{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<bool>> visited(H, vector<bool>(W));

    for( int row = 0; row < H ; row++){
        for( int col = 0; col < W; col++){

            if (!visited[row][col] && grid[row][col] == '1'){
                answer++;
                queue<pair<int,int>> q;
                q.push({row,col});
                visited[row][col] = true;

                // bfs algo
                while (!q.empty()){
                    pair<int,int> p = q.front();
                    q.pop();

                    for(pair<int,int> dir: directions){
                        int new_row = p.first + dir.first;
                        int new_col = p.second + dir.second;

                        if(inside(new_row, new_col) && !visited[new_row][new_col] && grid[new_row][new_col] == '1'){
                            q.push({new_row, new_col});
                            visited[new_row][new_col] = true;
                        }
                    }
                }
            }
        }
    }

    return answer;
}

int main(){

    int test;
    cin >> test;

    while(test--){

        int H,W;
        cin >> H >> W;

        vector<vector<char>> grid(H, vector<char>(W));

        for(int row = 0; row < H; row++){
            for(int col = 0; col < W; col++){
                cin >> grid[row][col];
            }
        }
        cout << numOfIslands(grid) << endl;
    }
}