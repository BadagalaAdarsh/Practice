#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

string find_multiple(int n) {

    if (n == 1) {
        return "1";
    }

    vector<string> dp(n);
    dp[1] = "1";

    queue<int> bfs;
    bfs.push(1);

    while(!bfs.empty()) {
        int r = bfs.front();
        bfs.pop();

        if (r == 0) {
            return dp[r];
        }

        for(int digit: {0,1}) {
            int new_r = (10 * r + digit) % n;

            if (dp[new_r].empty()){ // as wer finding the smallest we don't want to
                                    // replace the old string because it will obviously will be the shortest one
            // if (dp[new_r] == 0)
                bfs.push(new_r);
                dp[new_r] = dp[r] + char('0' + digit);     
            }
        }
    }

    assert(false);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int test ;
    cin >> test;

    while(test--) {
        int n;
        cin >> n;
        cout << find_multiple(n) << endl;
    }
}