/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space
*/

#include<bits/stdc++.h>
using namespace std;


// here we are using the concept of tortoise and hare
// just like finding the cycle in a linked list
// one pointer moves twice as fast as the other
// once they meet once slow pointer is set to 0 and both are incremented at same speed
int find_duplicate(vector<int>& nums) {

    int slow = nums[0];
    int fast = nums[nums[0]];

    // here we are finding the first collision
    while(slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    // setting the slow pointer to start
    // here we are finding the second collision
    // which is nothing but the duplicate number
    slow = 0;
    while(slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int answer = find_duplicate(nums);

    cout << answer << endl;
}