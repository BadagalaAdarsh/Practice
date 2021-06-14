/* 
How many ways you can reach nth stair from 0th stair if you can make a jump of
1 or 2 stairs
*/

// code chef link to test :- https://www.codechef.com/problems/JAM11

#include<bits/stdc++.h>
#define endl "\n" // defining end line with new line cause endline needs to flush the output stream which is bit slow
#define MOD 1000000007
using namespace std;


int main() {

    // just to make the execution bit faster by removing the sync of input and output
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;

    vector<int> dp(100001); // max number that will be asked in the question

    dp[1] = 1; // initially one
    dp[2] = 2; // 1 from previous and 2 at a time so 1 + 1
    dp[3] = 4; // 1+2 of previous and 3 steps at a time so 1+2+1 

    for(int i = 4; i <= 100001; i++) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD; 
    }

    while(test--) {

        int n;
        cin >> n;

        cout << dp[n] << endl;
    }
}
