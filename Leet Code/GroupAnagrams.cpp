
#include<bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs){

    unordered_map<string,vector<string>> hashtable;

    for(string word: strs){
        string str_copy = word;
        sort(str_copy.begin(), str_copy.end());
        hashtable[str_copy].push_back(word);
    }

    vector<vector<string>> answer;

    for(auto pointer: hashtable){
        answer.push_back(pointer.second);
    }

    return answer;
}

int main()
{
    vector<string> array;

    int n;
    cin >> n;

    for(int i=0; i<n ; i++)
    {
        string temp;
        cin >> temp;
        array.push_back(temp);
    }

    vector<vector<string>> answer;
    answer = groupAnagrams(array);

    for(auto pointer: answer){
        for(auto pointer2: pointer){
            cout << pointer2 << endl;
        }
    }

    return 0;
}