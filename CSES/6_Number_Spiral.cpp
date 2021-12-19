#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main() {

    int test;
    cin >> test;

    while(test--) {
        ll row, col;
        cin >> row >> col;

        ll maxi = max(row , col);
        ll start  = (maxi - 1) * (maxi - 1);
        ll ans;

        // if max number is odd
        if ( maxi%2 ) {
            if (row == maxi) {
                ans = start + col;
            }
            else {
                ans = start + 2 * maxi - row ;
            }
        }

        else {
            if (col == maxi){
                ans = start + row;
            }
            else{
                ans = start + 2 * maxi - col;
            }
        }

        cout << ans << "\n";
    }
}

        