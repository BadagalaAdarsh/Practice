/*
Given an integer numRows, return the first numRows of Pascal's triangle.
*/

// Program to print the pascals triangle
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generatePascalTriangle(int numRows) {
    vector<vector<int>> res;

    for(int i = 0; i < numRows; i++) {
        // vector store the individual row
        // initialize the vector with 1
        vector<int> row(i+1);

        // initialize first and last to 1
        row[0] = 1;
        row[i] = 1;

        for(int j = 1; j < i; j++) {
            // calculate the value of the element
            row[j] = res[i-1][j-1] + res[i-1][j];
        }
        res.emplace_back(row);
    }

    return res;
}

int main() {

    int n;
    cin >> n;

    vector<vector<int>> pascal(n, vector<int>(n));

    pascal = generatePascalTriangle(n);

    // printing the solution
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < pascal[i].size(); j++) {
            cout << pascal[i][j] << " ";
        }
        cout << endl;
    }

}
