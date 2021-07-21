/*
Suppose you have n integers from 1 to n. We define a beautiful arragement as an array that 
is constructed by these n numbers successfully if one of the following is true for the ith
position ( 1 <= i <= n) in this array.
The number at the ith position is divided by i
i is divisible by the number at ith position    

Given an integer n, return the number of the beautiful arrangements that you can construct
*/

#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int result = 0;

// this implementation is by swapping the values instead of backtracking
// which may improve the time complexity slightly

void swap(vector<int>& nums, int i, int j ) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void dfsback(vector<int>& nums, int val) {
    // as we are coming from back check val == 0 
    if (val == 0){
        result++;
        return;
    }

    // traversing in backward manner;
    for(int i = val; i > 0; i--) {
        swap(nums, i, val );
        if(nums[val] % i == 0 || val % nums[i] == 0 ) {
            dfsback(nums, val - 1 );
        }
        swap(nums, i , val);
    }
}

int countArrangement_2(int n) {
    vector<int> nums(n+1);

    for(int i = 1; i <= n; i++) nums[i] = i;
    // calling dfsfrom back
    dfsback(nums, n);
    return result;
}


// below implementation is using backtracking
void dfs(vector<int>& nums, int val, int n) {

    if (val > n) {
        result++;
        return;
    }

    for(int i = 1; i <= n ; i++) {
        if (nums[i] == 0 && (val % i == 0 || i % val == 0)) {
             nums[i] = val;
             dfs(nums, val + 1, n);
             nums[i] = 0; // here we are making it 0 because after completion of backtrack we need
                          // to get back

        }
    }
}

int countArrangements(int n) {

    vector<int> nums(n+1); // we have taken upto n+1 so that we can leave the 0th index and start from 1
    dfs(nums, 1, n);
    return result;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cout << countArrangements(n) << endl;

}