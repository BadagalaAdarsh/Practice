#include<bits/stdc++.h>
using namespace std;

int lastStoneweight(vector<int>& stones){

    priority_queue<int> answer(stones.begin(), stones.end());

    while(answer.size() >= 2){
        int y = answer.top();
        answer.pop();

        int x = answer.top();
        answer.pop();

        if (x != y){
            answer.push(y-x);
        }
    }

    if (answer.size() == 0){
        return 0;
    }

    return answer.top();
}


int main(){
    int test;

    cin >> test;

    while(test--){

        int n;
        cin >> n;

        vector<int> stones(n);

        for(int i=0; i<n; i++){
            cin >> stones[i];
        }

        cout << lastStoneweight(stones) << endl;
    }

    return 0;
}