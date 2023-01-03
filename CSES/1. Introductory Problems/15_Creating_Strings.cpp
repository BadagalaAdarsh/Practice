#include<bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;


int main() {

    string str;
    cin >> str;

    sort(str.begin(), str.end());

    vector<string> answer;

    do {

        answer.push_back(str);
        
    } while( next_permutation(str.begin(), str.end()));


    cout << answer.size() << endl;

    for(string word: answer) {
        cout << word << endl;
    }
}


