#include<bits/stdc++.h>
using namespace std;

string remove(string str){
    string str2;

    for(auto ch: str){
        if(ch == '#'){
            if(!str2.empty()){
                str2.pop_back();
            }
        }
        else{
            str2 += ch;
        }
    }

    return str2;
}

bool backSpaceCompare(string s, string t){
    return remove(s) == remove(t);
}

int main(){
    string s;
    cin >> s;
    string t;
    cin >> t;

    cout << backSpaceCompare(s,t) << endl;

    return 0;
}