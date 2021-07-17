#include<bits/stdc++.h>
#define endl "\n";
using namespace std;

unordered_map<int,int> check;

int staircase(int N) {

    if (N==1 || N==2) return N;

    if (check.find(N) != check.end()){
        return check[N];
    }
    check[N] = staircase(N-1) + staircase(N-2);
    return check[N];
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;

    while(test--) {
        int N;
        cin >> N;

        cout << staircase(N) << endl;
    }
}