#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin>> test;

    while (test--){

        int a,b;

        cin >> a >> b ;

        if (2*a > b){
            cout << -1 << " " << -1 << endl;
        }

        else{
            cout << a << " " << 2*a << endl;
        }
    }

    return 0;
}