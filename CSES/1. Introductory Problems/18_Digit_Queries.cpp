#include<bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

int main() {

    int queries;
    cin >> queries;


    int start = 1;

    string str = "1";

    while(str.size() < 1e18) {
        str += to_string(++start);
    }

    while(queries--) {

        ll k;
        cin >> k;

        cout << str[k] << endl;
    }
}
