#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<string> generate(int N) {

    vector<string> answer;
    queue<string> temp;

    answer.push_back("1");
    temp.push("1");

    while(answer.size() != N) {
        string s = temp.front();
        temp.pop();

        answer.push_back(s+"0");
        temp.push(s+"0");

        if (answer.size() == N)
            break;

        answer.push_back(s+"1");
        temp.push(s+"1");
    }

    return answer;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;

    while(test--) {
        int N;
        cin >> N;

        vector<string> answer = generate(N);

        for(auto num: answer) {
            cout << num << " ";
        }
    }
}