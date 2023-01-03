#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;



int main() {

    int n;
    cin >> n;

    const int k = n;

    for(int i = 0;  i < ( 1 << n) ; i++) {
        int temp = ( i ^ (i >> 1));

        string str = (bitset<16>(temp).to_string()) ;
        
        reverse(str.begin(), str.end());

        string answer = "";
        for(int j = 0; j < n; j++){
            answer += str[j];
        }

        reverse(answer.begin(), answer.end());
        cout << answer << endl;

    }

}

