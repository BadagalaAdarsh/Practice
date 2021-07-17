/*
Given an array of non-negative integers nums, you are initially positioned at the 
first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index. 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, 
which makes it impossible to reach the last index.
*/

#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& array){
    int n = array.size();
    int can_jump = 0;

    for(int i = 0; i < n; i++){
        if ( i > can_jump){
            return false;
        }
        if (can_jump >= n-1){
            break;
        }
        can_jump = max(can_jump, i + array[i]);
    }
    return true;
}

bool canJumpErrichtoVersion(vector<int>& array){
    int n = array.size();
    if(n<=1){
        return true;
    }
    pair<int,int> interval{0,0};
    
    while(true){
        int can_reach = -1;
        for(int i = interval.first; i <= interval.second; i++){
            can_reach = max(can_reach, i + array[i]);
        }
        if(can_reach >= n-1){
            return true;
        }
        interval = {interval.second+1, can_reach};

        if(interval.first > interval.second){
            return false;
        }
    }
    assert(false);
}

bool errichtoSimple(vector<int>& array){
    int n = array.size();
    if (n <= 1){
        return true;
    }
    int can_reach = 0;

    for(int i = 0; i <= can_reach; i++){
        if (i == n-1){
            return true;
        }
        can_reach = max(can_reach, i + array[i]);
    }
    return false;
}

int main(){
    int test;
    cin >> test;
    
    while(test--){
        int n;
        cin >> n;

        vector<int> array(n);
        for(int i = 0; i < n; i++){
            cin >> array[i];
        }
        cout << canJump(array) << endl;
    }
}