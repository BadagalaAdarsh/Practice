#include<bits/stdc++.h>
using namespace std;

// Complexity of the below method is O(row * log(W)) because we are applying binary search for every 
// row in the 2D array or the matrix
int leftMostColumn(vector<vector<int>>& matrix){
    int H = matrix.size();
    int W = matrix[0].size();
    int answer = W;

    for(int row = 0; row < H; row++) {
        int low = 0, high = W - 1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(matrix[row][mid] == 1){
                answer = min(answer,mid);
                high = mid - 1;
            }
            else {
                low = mid - 1;
            }
        }
    }
    if (answer == W){
        answer = -1;
    }
    return answer;
}


// better approach is to limit the binary search of the next row to the high equal to answer of previous
// one because say we have 00000000000000111111
//                         00000000000000000111 here it is clear that we don't need to check at all
// because it won't be the answer any way so here we can skip by doing only one query that is
// check if high (high = best of previous) is 0 or 1 
// modified method can be seen below

int leftMostColumnModified(vector<vector<int>>& matrix){
    int H = matrix.size();
    int W = matrix[0].size();
    int answer = W;

    for(int row = 0; row < H && answer != 0; row++) {
        int low = 0, high = answer - 1;
        while(low <= high) {
            int mid = low + (high - low)/2;

            if(matrix[row][high] == 0){
                continue;
            }
            
            if(matrix[row][mid] == 1){
                answer = min(answer,mid);
                high = mid - 1;
            }
            else {
                low = mid - 1;
            }
        }
    }
    if (answer == W){
        answer = -1;
    }
    return answer;
}

int main(){
    int test;
    cin >> test;

    while(test--){
        int row,col;
        cin >> row >> col;

        vector<vector<int>> matrix(row, vector<int>(col));
        for(int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                cin >> matrix[i][j];
            }
        }

        cout << leftMostColumn(matrix) << endl;
    }
}