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
//                 cout << "NO SOLUTION" << endl;
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
//             oddCount = currentCount;
//             continue;
//         }

//         currentCount = currentCount/2;

//         char currentChar = itr->first;

//         while(currentCount--) {
//             answer += currentChar;
//         }
//     }

//     string reverseAnswer = answer;
//     reverse(reverseAnswer.begin(), reverseAnswer.end());

//     for(int i = 0; i < oddCount; i++) {
//         answer += oddChar;
//     }

//     answer += reverseAnswer;    

//     cout << answer << endl;
// }

int main() {

    string str;
    cin >> str;

    int character[26]= {}, oddCount = 0;

    for(char ch: str) {
        ++character[ch - 'A'];
    }


    // count odd frequencies
    for(int i = 0; i < 26; i++) {
        oddCount += character[i] & 1;
    }

    if (oddCount > 1 ) {
        cout << "NO SOLUTION" ;
        return 0;
    }

    string answer;

    for(int i = 0; i < 26; i++) 
        // condition for even frequencies
        if(character[i] & 1 ^ 1) 
            for(int j = 0; j < character[i]/2; ++j)
                answer += (char)('A' + i);

    cout << answer;

    for(int i = 0; i < 26; i++) {
        if(character[i] & 1) {
            for(int j = 0; j < character[i]; j++) {
                cout << (char)('A' + i);
            }
        }
    }

    reverse(answer.begin(), answer.end());

    cout << answer;
}



    

