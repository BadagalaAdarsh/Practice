#include<bits/stdc++.h>
#define endl "\n"

int stairs(int N) {

    if (N == 1) {
        return 1;
    }

    if (N == 2) {
        return 2;
    }

    return stairs(N-1) + stairs(N-2);
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

        cout << stairs(N) << endl;
    }
}