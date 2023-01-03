/*
Contiguous Array

Solution
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/

#include<bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int>& nums){

    for(int i=0; i< (int)nums.size(); i++){
        if (nums[i] == 0){
            nums[i] = -1;
        }
    }

    vector<int> prefix_sum;
    prefix_sum.push_back(0);

    for(auto num: nums){
        prefix_sum.push_back(prefix_sum.back() + num);
    }

    unordered_map<int,int> first_occ;

    int answer= 0;

    for(int i=0; i<(int)prefix_sum.size(); i++){
        int x = prefix_sum[i];
        auto it = first_occ.find(x);

        if (it != first_occ.end()){
            answer = max(answer, first_occ[x]);
        }
        else{
            first_occ[x] = i;
        }
    }
    return answer;
}

int main(){

    int test;
    cin >> test;

    while (test--){
        
        int n;
        cin >> n;

        vector<int> array(n);

        for(int i=0 ; i < n; i++){
            cin >> array[i];
        }

        cout << findMaxLength(array) << endl;

    }
    
    return 0;
}