/*
  Product of Array Except Self

Solution
Given an integer array nums, return an array answer such that answer[i] is equal to the 
product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? 
(The output array does not count as extra space for space complexity analysis.)
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums){

    int n = nums.size();
    vector<int> prefix_prod;
    prefix_prod.push_back(1);

    for(auto num: nums){
        prefix_prod.push_back(prefix_prod.back() * num);
    }

    vector<int> suffix_prod(n+1);
    suffix_prod[n] = 1;

    for(int i = n-1; i >= 0; i--){
        suffix_prod[i] = suffix_prod[i+1] * nums[i];
    }

    vector<int> answer(n);

    for(int i = 0; i < n; i++){
        answer[i] = prefix_prod[i] * suffix_prod[i+1];
    }

    return answer;
}

int main(){

    int test;
    cin >> test;

    while(test--){
        int n ;
        cin >> n;

        vector<int> nums(n);

        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        vector<int> answer;
        answer = productExceptSelf(nums);

        for(int numbers: answer){
            cout << numbers << " " ;
        }

        cout << endl;
    }
}