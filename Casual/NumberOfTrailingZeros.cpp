#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int count_zeros(int num) {

    if (num <= 4) {
        return 0;
    }

    int count = 0;
    for(int i = 5; num/i  >= 1; i *= 5) {
        count += num/i;
    }

    return count;
}

int count_zeros_version_2 (int num) {

    if (num <= 4) {
        return 0;
    }

    int count = 0;

    while (num >= 5) {
        num /= 5;
        count += num;
    }

    return count;
}

int main () {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;

    while(test--) {

        int num;
        cin >> num;

        cout << count_zeros(num) << endl;
    }
}