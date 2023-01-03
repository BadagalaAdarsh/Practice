#include<bits/stdc++.h>
using namespace std;

bool backspacestring(string s, string t){
    int i = s.length() -1, j= t.length()-1;
    int skip_s = 0, skip_t =0;

    while (i>=0 || j>=0){

        while (i>=0){
            if(s[i]=='#'){
                skip_s++;
                i--;
            }
            else if(skip_s > 0){
                skip_s--;
                i--;
            }
            else{
                break;
            }
        }
        while (j>=0){
            if(t[j] == '#'){
                skip_t++;
                j--;
            }
            else if(skip_t > 0){
                skip_t--;
                j--;
            }
            else{
                break;
            }
        }

        if(i>=0 && j>=0 && s[i] != t[j]){
            return false;
        }
        if((i>=0) != (j>=0)){
            return false;
        }
        i--;
        j--; 
    }
    return true;
}

int main()
{
    int test;
    cin >> test;

    while(test--){  
        string s, t;
        cin >> s;
        cin >> t;

        cout << backspacestring(s,t) << endl;
    }
    return 0;
}