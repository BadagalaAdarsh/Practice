#include<bits/stdc++.h>
using namespace std;

map<pair<string,string>,int> answer;

int LongestCommonSubsequence(string text1, string text2){
    int length1 = text1.length();
    int length2 = text2.length();

    vector<vector<int>> dp(length1+1, vector<int>(length2+1));
    dp[0][0] = 0;

    for(int i=0; i< length1; i++){
        for(int j=0; j<length2; j++){
            
            if(text1[i] == text2[j]){
                dp[i+1][j+1] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }

    return dp[length1][length2];
}

int main()
{
    string text1;
    cin >> text1;

    string text2;
    cin >> text2;

    cout << LongestCommonSubsequence(text1, text2) << endl;

    return 0;
}