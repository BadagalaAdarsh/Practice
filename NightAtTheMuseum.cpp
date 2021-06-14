#include<bits/stdc++.h>
using namespace std;

int main(){

    string input_str;
    cin >> input_str;

    int answer = 0;
    int prev = 0;

    for(auto ch: input_str){
        int pos = int(ch) - int('a');;
        int temp = min(abs(prev-pos), 26-abs(prev - pos));
        answer += temp;
        prev = pos;
    }

    cout << answer << endl;

    return 0;
}