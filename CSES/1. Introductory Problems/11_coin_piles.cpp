#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;


int main() {

    int test;
    cin >> test;

    while(test--) {

        int a, b;
        cin >> a >> b;

        // first sum should be divisible by 3 , 2 times of one should be greater than or equal to other
        // similarly 2 times of other should be greater than or equal to other
        // 2 times because if we are removing 2 from a, we are removing 1 from b so a should have atleast
        // 2 times more coin from b

        if ( ((a + b) % 3 == 0 ) && 2 * a >= b && 2 * b >= a) {
            cout << "YES" << endl;
        }

        else {
            cout << "NO" << endl;
        }
    }
}