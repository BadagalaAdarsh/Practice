#include<bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

bool leftDiagonal[16], rightDiagonal[16], columns[8];

void getTotalWays(int row, int& answer, char chess[][8]) {


    // if reach end of the board that means we have placed all the queens
    if(row == 8){
        answer++;
        return;
    }

    for(int col = 0; col < 8; col++) {

        if (chess[row][col] == '.' && leftDiagonal[row + col] == false && 
                rightDiagonal[row - col + 7] == false && columns[col] == false) {
                    leftDiagonal[row + col] = true;
                    rightDiagonal[row - col + 7] = true;
                    columns[col] = true;

                    getTotalWays(row+1, answer, chess);

                    leftDiagonal[row + col] = false;
                    rightDiagonal[row - col + 7] = false;
                    columns[col] = false;
                }
    }
}


int main() {

    char chess[8][8];

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cin >> chess[i][j];
        }
    }

    int answer = 0;
    getTotalWays(0, answer, chess);

    cout << answer;
}