#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int k = 1; k <= n; k++) {
                                        // general formual n(n-1)/2 is used to find out
                                        // number of ways to choose two elements out of n
                                        // you can get above one using nCr formula
        ll totalPositions = k * k, totalWaysOfPlacingKnights = totalPositions * (totalPositions - 1) / 2;

        if (k > 2)
            totalWaysOfPlacingKnights -= 4 * (k - 1) * (k-2);

        cout << totalWaysOfPlacingKnights << endl;
    }
}
