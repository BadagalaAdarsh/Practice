/*
https://leetcode.com/problems/regions-cut-by-slashes/

An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'
*/

#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<string> grid;
vector<vector<vector<bool>>> visited;
int height, width;

bool inside(int row, int col) {
    return 0 <= row && row < height && 0 <= col && col < width;
}



void dfs(int row, int col, int type) {

    if(!inside(row,col) || visited[row][col][type]){
        return ;
    }

    visited[row][col][type] == true;

    if (type == 0){
        dfs(row - 1, col, 2); // above
    }

    else if (type == 1) {
        dfs(row, col + 1, 3); // right;
    }

    else if (type == 2) {
        dfs(row + 1, col, 0); // below;
    }

    else if (type == 3) {
        dfs(row, col - 1, 1); // left
    }

    if(grid[row][col] != '/'){
        dfs(row, col, type ^ 1);
    }

    if(grid[row][col] != '\\'){
        dfs(row, col, type ^ 3);
    }
}

int regionBySlashes(vector<string>& _grid){
    grid = _grid;
    height = grid.size();
    if (height == 0){
        return 0;
    }
    width = grid[0].size();
    int regions = 0;

    visited.clear();
    visited.resize(height, vector<vector<bool>>(width, vector<bool>(4)));

    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            for(int type = 0; type < 4; type++) {
                if (!visited[row][col][type]){
                    dfs(row, col, type);
                    regions++;
                }
            }
        }
    }
    return regions;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;

    while(test--) {
        
        int n;
        cin >> n;

        vector<string> grid(n);

        for(int i = 0; i < n; i++) cin >> grid[i];

        cout << regionBySlashes(grid) << endl;
    }
}