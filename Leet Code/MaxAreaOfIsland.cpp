#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<vector<int>>& grid) {
    int H = grid.size();
    if (H == 0) {
        return 0;
    }

    int W = grid[0].size();
    int answer = 0;

    vector<vector<bool>> visited(H, vector<bool>(W));
    vector<pair<int,int>> directions {{1,0}, {0,1}, {-1,0}, {0,-1}};

    auto inside = [&](int row, int col) {
        return 0 <= row && row < H && 0 <= col && col < W;
    };

    for(int row = 0; row < H; row++) {
        for (int col = 0; col < W; col++) {
            int current = 0;

            if (!visited[row][col] && grid[row][col] == 1){
                current++;
                queue<pair<int,int>> q;
                visited[row][col] = true;

                answer = max(answer, current);

                while(!q.empty()) {
                    pair<int,int> p = q.front();
                    q.pop();

                    for(pair<int,int> dir: directions) {
                        int new_row = dir.first + p.first;
                        int new_col = dir.second + p.second;

                        if( inside(new_row, new_col) && !visited[new_row][new_col] && grid[new_row][new_col] == 1){
                            visited[new_row][new_col] = true;
                            q.push({new_row,new_col});
                            current++;
                            answer = max(answer, current);
                        }
                    }
                }
            }
        }
    }

    return answer;
}

int main() {
    int test;
    cin >> test;

    while(test-- ) {
        int row, col;
        cin >> row >> col ;

        vector<vector<int>> grid(row,vector<int>(col));

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                cin >> grid[i][j];
            }
        }

        cout << maxArea(grid) << endl;
    }
}