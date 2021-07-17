/*
 Last Stone Weight

Solution
We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two heaviest stones and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)

 

Example 1:

Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
 

Note:

1 <= stones.length <= 30
1 <= stones[i] <= 1000
*/

#include<bits/stdc++.h>
using namespace std;

int lastStone(vector<int>& stones){
    multiset<int> answer;

    for(auto stone: stones){
        answer.insert(stone);
    }

    auto pop_max = [&](){
        int x = *answer.rbegin();
        answer.erase(prev(answer.end()));
        return x;
    };

    while(answer.size() >= 2){
        int y = pop_max();
        int x = pop_max();

        if (x!=y){
            answer.insert(y-x);
        }
    }

    if (answer.size()==0){
        return 0;
    }

    return pop_max();
}

int main(){
    int test;
    cin >> test;

    while (test--){
        
        int n;

        cin >> n;
        vector<int> array;

        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            array.push_back(temp);
        }

        cout << lastStone(array) << endl;
    }

    return 0;
}