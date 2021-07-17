#include<bits/stdc++.h>
using namespace std;

void remove(string& str, int& len){

    for(int i=0; i<(int)str.length(); i++){
        if(str[i] == '#'){
            if(len > 0){
                len--;
            }
        }
        else{
            str[len] = str[i];
            len++;
        }
    }
}

bool BackSpaceString(string s, string t){
    int len_s = 0, len_t = 0;
    remove(s,len_s);
    remove(t,len_t);

    if(len_s != len_t){
        return false;
    }

    for(int i=0; i < len_s ; i++){
        if(s[i] != t[i]){
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    string t;
    cin >> s;
    cin >> t;

    cout << BackSpaceString(s,t) << endl;

    return 0;
}