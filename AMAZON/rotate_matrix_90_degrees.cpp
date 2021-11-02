/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
*/

#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // first we need to transpose the matrix in-place
    for(int i = 0;  i < n; i++) {
        for(int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // then we need to reverse the rows
    for(int i = 0; i < n; i++)
        reverse(matrix[i].begin(), matrix[i].end());
}

int main(){
    
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) 
            cin >> matrix[i][j];

    rotate(matrix);

    // printing the rotated matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) 
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}