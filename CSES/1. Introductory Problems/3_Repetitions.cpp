#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main() {

    string str;
    cin >> str;

    int ans = 0, currentCount = 0;
    char prev = 'A';

    for(char currentChar: str) {
        if(currentChar == prev) {
            currentCount++;
            ans = max(ans, currentCount);
        }
        else{
            prev = currentChar;
            currentCount = 1;
        }
    }

    cout << ans ;
}