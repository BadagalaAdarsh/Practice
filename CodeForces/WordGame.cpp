#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

void print(set<string>& person){
    cout << "person values are " << endl;
    for(string word: person){
        cout << word << " ";
    }
    cout << endl;
}

bool wordIn(set<string>& person, string& word){
    return person.find(word) != person.end();
}

bool wordNotIn(set<string>& person, string& word){
    return person.find(word) == person.end();
}

int getScore(set<string>& person1, set<string>& person2, set<string>& person3){
    
    int score = 0;
    
    for(string word: person1){
        
        if (wordIn(person2,word) && wordIn(person3, word)) 
            score += 0;
            
        else if(wordNotIn(person2, word) && wordNotIn(person3, word))
            score += 3;

        else
            score += 1;
        
    }
    return score;
}

void readData(set<string>& person, int n){
    string word;
    
    for(int i = 0; i < n; i++) {
        cin >> word;
        person.insert(word);
    }
}

void solve() {
    
    int n;
    cin >> n;
    // cout << "n is " << n << endl;
    set<string> person1;
    set<string> person2;
    set<string> person3;
    
    readData(person1, n);
    readData(person2, n);
    readData(person3, n);
    
    // print(person1);
    // print(person2);
    // print(person3);
    
    
    int firstPersonScore = getScore(person1, person2, person3);
    int secondPersonScore = getScore(person2, person1, person3);
    int thirdPersonScore = getScore(person3, person1, person2);
    
    cout << firstPersonScore << " " << secondPersonScore << " " << thirdPersonScore << endl;
    
}


int main() {
    
    
    int test;
    cin >> test;
    
    while(test--) {
        // cout <<"entered test" << endl;
        solve();
    }
}
