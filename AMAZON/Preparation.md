# My Amazon Preparation

## Coding Questions

#### [In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:](https://leetcode.com/problems/pascals-triangle/)


```cpp
/*
Given an integer numRows, return the first numRows of Pascal's triangle.
*/

// Program to print the pascals triangle
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generatePascalTriangle(int numRows) {
    vector<vector<int>> res;

    for(int i = 0; i < numRows; i++) {
        // vector store the individual row
        // initialize the vector with 1
        vector<int> row(i+1);

        // initialize first and last to 1
        row[0] = row[i] = 1;

        for(int j = 1; j < i; j++) {
            // calculate the value of the element
            row[j] = res[i-1][j-1] + res[i-1][j];
        }
        res.emplace_back(row);
    }

    return res;
}

int main() {

    int n;
    cin >> n;

    vector<vector<int>> pascal;

    pascal = generatePascalTriangle(n);

    // printing the solution
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < pascal[i].size(); j++) {
            cout << pascal[i][j] << " ";
        }
        cout << endl;
    }

}
;
```

#### [Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.](https://leetcode.com/problems/next-permutation/)

#### If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

#### The replacement must be in place and use only constant extra memory.

##### Example
* input = [1,2,3]
* output = [1,3,2]

``` cpp
#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();

    // find the first element that is smaller than its next element
    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1])
        i--;
        
    // if no such element exists, then the array is already in descending order
    if (i >= 0) {
        // find the first element that is greater than nums[i]
        int j = n - 1;
        while (j >= 0 && nums[j] <= nums[i])
            j--;
        
        // swap nums[i] and nums[j]
        swap(nums[i], nums[j]);
    }

    // reverse the array from nums[i + 1] to the end
    reverse(nums.begin() + i + 1, nums.end());
}

int main() {

    int n;
    cin >> n;

    vector<int> array(n);

    for(int i = 0; i < n; i++) cin >> array[i];

    nextPermutation(array);

    // printing the array
    for(int i = 0; i < n; i++) cout << array[i] << " ";
    
}

// you can also directly use the next permutation method in cpp

(next_permutation(s.begin(), s.end());
```


#### [Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.You must do it in place](https://leetcode.com/problems/set-matrix-zeroes/)

```cpp
/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

You must do it in place.
*/

#include<bits/stdc++.h>
using namespace std;


void setZeroes(vector<vector<int>>& matrix) {
    bool col0 = false;
    int rows = matrix.size();
    int cols = matrix[0].size();

    for(int i = 0; i < rows; i++) {
        // check if first element is 0 that is top left 
        if (matrix[i][0] == 0) {
            col0 = true;
        }

        // then for rest of matrix if found 0 at any position mark the top right and left to 0
        // link to video solution is
        //https://www.youtube.com/watch?v=M65xBewcqcI&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=7

        for(int j = 1; j < cols; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }

    // now traverse the matrix in reverse order and set the matrix elements to 0 based on row and col
    // we are traversing the matrix in reverse because we are setting the elements to 0 based on row and col
    // and if we come from top if would change the top left one see the video for better explanation

    for(int i = rows - 1; i >= 0; i--){
        // below loop is ran only upto 1 do check it
        for(int j = cols - 1 ; j >= 1; j--) 
            if (matrix[i][0] == 0 || matrix[0][j] == 0) 
                matrix[i][j] = 0;

        if (col0) 
            matrix[i][0] = 0;
        
    }
}   

int main() {

    int row, col;
    cin >> row >> col;

    vector<vector<int>> matrix(row, vector<int>(col));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }

    setZeroes(matrix);

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
```

#### [Kadane Algorithms for max contiguos sub array](https://leetcode.com/problems/maximum-subarray/submissions/)

```cpp
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN;
        int temp = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            temp += nums[i];
            sum = max(temp,sum);
            temp = max(0, temp);
        }
        
        return sum;
    }
```

#### [given an array of 0s, 1s, and 2s, sort the array in-place.](https://leetcode.com/problems/sort-colors/)

Initialize the 3 pointers such that low and mid will point to 0th index and high pointer will point to last index
int low = 0

int mid = 0

int high = n-1

Now there will 3 different operations / steps based on the value of arr[mid] and will be repeated until mid <= high.

arr[mid] == 0:
swap(arr[low], arr[mid])
low++, mid++

arr[mid] == 1:
mid++

arr[mid] == 2:
swap(arr[mid], arr[high])
high–;
The array formed after these steps will be a sorted array.

This algorithm is also called as **Dutch National flag algorithm** 

Time Complexity is O(n) + O(n)
Space Complexity is O(1)

```cpp
#include<bits/stdc++.h>
using namespace std;

void sort_array(vector<int>& array) {

    int low = 0, mid = 0, high = array.size() - 1;

    while( mid <= high) {
        if (array[mid] == 0) {
            swap(array[low], array[mid]);
            low++;
            mid++;
        }

        else if (array[mid] == 1) {
            mid++;
        }

        else {
            swap(array[mid], array[high]);
            high--;
        }
    }
}


int main() {
    int n;
    cin >> n;

    vector<int> array(n);
    for(int i = 0; i < n; i++) {
        cin >> array[i];
    }

    sort_array(array);

    // printing the sorted array

    for(int i = 0; i < n ; i++) {
        cout << array[i] << " ";
    }

}
```

#### [You are given an array prices where prices[i] is the price of a given stock on the ith day.](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

#### You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

#### Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0

```cpp
#include<bits/stdc++.h>
using namespace std;

int best_time_to_buy_and_sell_stock(vector<int> stocks) {
    int min_price = INT_MAX;
    int max_profit = 0;
    for(int i = 0; i < stocks.size(); i++) {
        if(stocks[i] < min_price) {
            min_price = stocks[i];
        }
        max_profit = max(max_profit, stocks[i] - min_price);
    }
    return max_profit;
}

int main() {

    int n;
    cin >> n;

    vector<int> stocks(n);
    for(int i = 0; i < n; i++) cin >> stocks[i];

    int max_profit = best_time_to_buy_and_sell_stock(stocks);
    cout << max_profit << endl;
}
```

#### [Rotate the given 2D matrix by 90degrees](https://leetcode.com/problems/rotate-image/submissions/)

```cpp
#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // first we need to transpose the matrix in-place
    for(int i = 0;  i < n; i++) {
        for(int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // then we need to reverse the rows
    for(int i = 0; i < n; i++)
        reverse(matrix[i].begin(), matrix[i].end());
}

int main(){
    
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) 
            cin >> matrix[i][j];

    rotate(matrix);

    // printing the rotated matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) 
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
```

#### [Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.](https://leetcode.com/problems/merge-intervals/)

```cpp
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    vector<vector<int>> res;


    // sorting the 2d array based on the first number which uses lamda function
    sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
        return a[0] < b[0];
    });

    res.emplace_back(intervals[0]);

    // traverse the intervals vector and add to result based on the overlapping condition

    for(int i =1 ; i < (int)intervals.size(); i++){
        
        // if first number of next interval is smaller or equal to the last number of the previous interval
        if(intervals[i][0] <= res.back()[1]){
            // current last number will the max of current last and next last number
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        }
        else{
            // else directly add the next interval to the result
            res.emplace_back(intervals[i]);
        }
    }
    // return the result
    return res;
}



int main() {

    int n;
    cin >> n;

    vector<vector<int>> intervals(n);

    for(int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<vector<int>> answer = mergeIntervals(intervals);

    // print the final answer

    for(int i = 0; i < (int)answer.size(); i++) {
        cout << answer[i][0] << " " << answer[i][1] << endl;
    }
}
```

#### [You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.](https://leetcode.com/problems/merge-sorted-array/)

#### Merge nums1 and nums2 into a single array sorted in non-decreasing order.

#### The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.


```cpp
#include<bits/stdc++.h>
using namespace std;

int find_gap(int n) {
    // return the ceil of division by 2
    // for example, if n = 5, return 3
    // if n = 1 return 0 as ceil will be still 1 leading to infinite loop

    if (n == 1)
        return 0;

    else
        return (n + 1) / 2;
}


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
    int gap = find_gap(m+n);

    // add the elements of nums2 to nums1
    for (int i = 0; i < n; i++) {
        nums1[m + i] = nums2[i];
    }

    // sort the elements of nums1
    while( gap != 0 ) {

        int start = 0;
        int end = gap;

        while ( end < m + n ) {

            if (nums1[start] > nums1[end]) {
                swap(nums1[start], nums1[end]);
            }
            start++;
            end++;

        }

        gap = find_gap(gap);
    }
}

int main() {

    int m, n;
    cin >> m >> n;
    vector<int> nums1(m);
    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }
    vector<int> nums2(n);
    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }
    
    // print the final nums1 vector
    for (int i = 0; i < m; i++) {
        cout << nums1[i] << " ";
    }
}
```

#### [Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.](https://leetcode.com/problems/find-the-duplicate-number/)

#### There is only one repeated number in nums, return this repeated number.

#### You must solve the problem without modifying the array nums and uses only constant extra space.


```cpp
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
```

#### [You are given a read only array of n integers from 1 to n.](https://www.interviewbit.com/problems/repeat-and-missing-number-array/)

#### Each integer appears exactly once except A which appears twice and B which is missing.

#### Return A and B.

#### Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

#### Note that in your output A should precede B.

#### [To know why this solution works watch this video](https://www.youtube.com/watch?v=5nMGY4VUoRY&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=4)


```cpp
#include<bits/stdc++.h>
using namespace std;

vector<int> repeat_and_missing_number(vector<int> &A) {

    int n = A.size();
    int xor_of_all_numbers = 0;
    int xor_of_all_numbers_with_missing_number = 0;
    int xor_of_all_numbers_with_repeated_number = 0;

    for(int i=0;i<n;i++) {
        xor_of_all_numbers ^= A[i];
    }

    for(int i=1;i<=n;i++) {
        xor_of_all_numbers_with_missing_number ^= i;
    }

    xor_of_all_numbers_with_repeated_number = xor_of_all_numbers ^ xor_of_all_numbers_with_missing_number;

    int missing_number = xor_of_all_numbers_with_missing_number & ~xor_of_all_numbers_with_repeated_number;
    int repeated_number = xor_of_all_numbers_with_repeated_number & ~xor_of_all_numbers_with_missing_number;

    vector<int> ans;
    ans.push_back(repeated_number);
    ans.push_back(missing_number);

    return ans;
}

int main() {

    int n;
    cin >> n;

    vector<int> array(n);
    for(int i = 0; i < n; i++) cin >> array[i];

    vector<int> answer = repeat_and_missing_number(array);

    cout << answer[0] << " " << answer[1] << endl;
}
```

#### similar approach with bit better code and comments

```cpp
vector<int>Solution::repeatedNumber (const vector < int >&arr) {
    /* Will hold xor of all elements and numbers from 1 to n */
    int xor1;

    /* Will have only single set bit of xor1 */
    int set_bit_no;

    int i;
    int x = 0; // missing
    int y = 0; // repeated
    int n = arr.size();

    xor1 = arr[0];

    /* Get the xor of all array elements */
    for (i = 1; i < n; i++)
        xor1 = xor1 ^ arr[i];

    /* XOR the previous result with numbers from 1 to n */
    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;

    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 - 1);

    /* Now divide elements into two sets by comparing a rightmost set bit
       of xor1 with the bit at the same position in each element.
       Also, get XORs of two sets. The two XORs are the output elements.
       The following two for loops serve the purpose */

    for (i = 0; i < n; i++) {
        if (arr[i] & set_bit_no)
            /* arr[i] belongs to first set */
            x = x ^ arr[i];

        else
            /* arr[i] belongs to second set */
            y = y ^ arr[i];
    }

    for (i = 1; i <= n; i++) {
        if (i & set_bit_no)
            /* i belongs to first set */
            x = x ^ i;

        else
            /* i belongs to second set */
            y = y ^ i;
    }

    // NB! numbers can be swapped, maybe do a check ?
    int x_count = 0;
    for (int i=0; i<n; i++) {
        if (arr[i]==x)
            x_count++;
    }
    
    if (x_count==0)
        return {y, x};
    
    return {x, y};
}
```

# Dynamic Programming Adithya Verma


#### Knapsack

##### Memoization

```cpp

int knapsack(vector<int>& weights, vector<int>& prices, int W, int n, int[][] dp) {

    if (n == 0 || W == 0) {
        return 0;
    }

    if (dp[n][W] != -1) {
        return dp[n][W];
    }


    if (weights[n-1] <= W ) {
        return dp[n][W] = max(prices[n-1] + knapsack(weights, prices, W - w[n-1], n -1, dp) , knapsack(weights, prices, W, n-1, dp));
    }

    else{
        return dp[n][W] = knapsack(weights, prices, W, n-1, dp);
    }
}

```




