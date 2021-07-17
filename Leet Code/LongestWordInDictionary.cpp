#include<bits/stdc++.h>
using namespace std;

// using sorting
// time is nlogn for sorting and space is n for set
string longestWord(vector<string>& words) {

    sort(words.begin(), words.end());
    unordered_set<string> is_there;

    string answer;

    for(string check: words) {

        if (check.size() == 1 || is_there.count(check.substr(0, check.size()-1))){

            answer = check.size() > answer.size() ? check : answer;
            is_there.insert(check);
        }
    }
    return answer;    
}

int main(){
    int test;
    cin >> test;

    while(test--) {
        int n;
        cin >> n;

        vector<string> array(n);
        for(int i = 0; i < n; i++) {
            cin >> array[i];
        }

        cout << longestWord(array) << endl;
    }
}