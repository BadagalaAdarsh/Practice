#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

// below one is my loigc 

// int main() {

//     string str;
//     cin >> str;

//     map<char,int> hashmap;

//     for(char ch: str) {
//         hashmap[ch]++;
//     }

//     int oddCount = 0;

//     map<char,int>::iterator itr;
//     for(itr = hashmap.begin(); itr != hashmap.end(); itr++) {
//         int count = itr->second;

//         if (count%2 != 0) {
//             oddCount++;

//             if (oddCount > 1) {
//                 cout << "NO SOLUTION" ;
//                 return 0;
//             }
//         }
//     }

//     string answer;

//     char oddChar ;

//     for(itr = hashmap.begin(); itr != hashmap.end(); itr++) {
//         int currentCount = itr->second;

//         // if odd count 
//         if (currentCount % 2 != 0) {
//             oddChar = itr->first;
//         }

//         currentCount = currentCount/2;

//         char currentChar = itr->first;

//         while(currentCount--) {
//             answer += currentChar;
//         }
//     }

//     string reverseAnswer = answer;
//     reverse(reverseAnswer.begin(), reverseAnswer.end());

//     answer = answer + oddChar + reverseAnswer;

//     cout << answer;
// }


