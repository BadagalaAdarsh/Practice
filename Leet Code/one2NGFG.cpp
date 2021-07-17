#include<bits/stdc++.h>
using namespace std;

void printing(int n) {
    if ( n > 0 ) {
        
        printing(n-1);
        cout << n << " ";
    }
    
}

int main() {

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    while(test--) {
        int n;
        cin >> n;

        printing(n);
        cout <<  "\n";
    }
}