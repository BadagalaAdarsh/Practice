#include<bits/stdc++.h>
using namespace std;

map<pair<string,string>,int> answer;

int LongestCommonSubsequence(string text1, string text2){

    if (text1.empty() || text2.empty()){
        return 0;
    }

    auto it = answer.find({text1,text2});

    if (it != answer.end()){
        return it->second;
    }

    if (text1.back() == text2.back()){
        pair<string,string> my_state{text1, text2};
        text1.pop_back();
        text2.pop_back();
        return answer[my_state] = 1 + LongestCommonSubsequence(text1, text2);
    }

    return answer[{text1, text2}] = max(LongestCommonSubsequence(text1, string(text2.begin(), text2.end() -1)),
                                                LongestCommonSubsequence(text2,string(text1.begin(),text1.end()-1)));
}

int main()
{
    string text1;
    cin >> text1;

    string text2;
    cin >> text2;

    cout << LongestCommonSubsequence(text1, text2) << endl;

    return 0;
}