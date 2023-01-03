/*
April 30, 2020 Navneet R
You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:

direction can be 0 (for left shift) or 1 (for right shift). 
amount is the amount by which string s is to be shifted.
A left shift by 1 means remove the first character of s and append it to the end.
Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
Return the final string after all operations.

Example 1:

Input: s = “abc”, shift = [[0,1],[1,2]]
Output: “cab”
Explanation: 
[0,1] means shift to left by 1. “abc” -> “bca”
[1,2] means shift to right by 2. “bca” -> “cab”
Example 2:

Input: s = “abcdefg”, shift = [[1,1],[1,1],[0,2],[1,3]]
Output: “efgabcd”
Explanation:  
[1,1] means shift to right by 1. “abcdefg” -> “gabcdef”
[1,1] means shift to right by 1. “gabcdef” -> “fgabcde”
[0,2] means shift to left by 2. “fgabcde” -> “abcdefg”
[1,3] means shift to right by 3. “abcdefg” -> “efgabcd”
Constraints:

1 <= s.length <= 100
s only contains lower case English letters.
1 <= shift.length <= 100
shift[i].length == 2
0 <= shift[i][0] <= 1
0 <= shift[i][1] <= 100
*/

#include<bits/stdc++.h>
using namespace std;

string stringShift(string s, vector<vector<int>>& shift){
    int total = 0;

    for(auto element: shift){
        if(element[0] == 0){
            total -= element[1];
        }
        else{
            total += element[1];
        }
    }

    int n = s.length();
    total %= n;

    if(total < 0){
        total += n;
    }

    return s.substr(n-total) + s.substr(0,n - total);
}

int main(){

    int test;
    scanf("%d",&test);

    while (test--){
        string s;
        cin >> s;

        vector<vector<int>> shifts;

        int n;
        for(int i = 0; i < n; ++i){
            vector<int> temp(2);
            for(int j = 0; j < 2; ++j){
                cin >> temp[i];
            }
            shifts.push_back(temp);
        }

        cout << stringShift(s,shifts) << endl ;
    }
}