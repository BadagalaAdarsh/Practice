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

#### [Search in 2d Matrix](https://leetcode.com/problems/search-a-2d-matrix/)

#### [Solution](https://leetcode.com/problems/search-a-2d-matrix/discuss/26220/Don't-treat-it-as-a-2D-matrix-just-treat-it-as-a-sorted-list)

```cpp

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0;
        if(!matrix.size()) return false;
        int hi = (matrix.size() * matrix[0].size()) - 1;
        
        while(lo <= hi) {
            int mid = (lo + (hi - lo) / 2);
            if(matrix[mid/matrix[0].size()][mid % matrix[0].size()] == target) {
                return true;
            }
            if(matrix[mid/matrix[0].size()][mid % matrix[0].size()] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return false;
    }
};

```

#### [Pow(x,n)](https://leetcode.com/problems/powx-n/)

#### [Solution](https://www.youtube.com/watch?v=l0YC3876qxg&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=15)

```cpp

class Solution {
public:
    double myPow(double x, int n) {
        
        double ans = 1.0;
        
        long long nn = n;
        
        // if given power is negative converting it to positive
        if (nn < 0) nn = (long long)-1 * (long long) n;
        
        while(nn) {
            
            // if current power is odd
            // multiply x to ans and decrease nn by one
            if (nn%2) {
                ans = ans * x;
                nn--;
            }
            
            // else multiply x with itself and reduce nn by half
            else{
                x = x * x;
                nn /= 2;
            }
        }
        
        // if n was negative
        if (n < 0 ) ans = (double)(1.0)/(double)(ans);
        
        return ans;       
        
    }
};

```

#### [Majority Element](https://leetcode.com/problems/majority-element/)

* Given an array nums of size n, return the majority element.
* The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.


#### [Video Solution](https://youtu.be/AoX3BPWNnoE?list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2)

#### This algorithm is called Moore Voting Algorithm


```cpp

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count = 0;
        int element = 0;
        
        for(int num: nums){
            
            if (count == 0){
                element = num;
            }
            
            if (num == element){
                count++;
            }
            
            else{
                count--;
            }
        }
        
        return element;
    }
};

```

#### [Majority Element II](https://leetcode.com/problems/majority-element-ii/)

* Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

#### [Video Solution](https://www.youtube.com/watch?v=yDbkQd9t2ig&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=18)

#### This is extended Moores Voting algorithm also called Boyers Moore Voting Algorithm

```cpp

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int sz = nums.size();
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
        
        for(int i = 0; i < sz; i++) {
            
            if (nums[i] == num1) {
                count1++;
            }
            
            else if (nums[i] == num2) {
                count2++;
            }
            
            else if (count1 == 0) {
                num1 = nums[i];
                count1++;
            }
            
            else if (count2 == 0) {
                num2 = nums[i];
                count2++;
            }
            
            else{
                count1--;
                count2--;
            }
        }
        
        vector<int> ans;
        count1 = count2 = 0;
        
        for(int i = 0; i < sz; i++) {
            if (nums[i] == num1){
                count1++;
            }
            
            else if (nums[i] == num2) {
                count2++;
            }
        }
        
        if (count1 > sz/3) {
            ans.push_back(num1);
        }
        
        if (count2 > sz/3) {
            ans.push_back(num2);
        }
        
        return ans;
    }
};

```






# ###########################################################################

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

##### Tabulation Method

```cpp

int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    vector<vector<int>> dp(n+1, vector<int>(W+1));

    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {

            if ( i == 0 || w == 0) {
                dp[i][w] = 0;
            }

            else if (wt[i-1] <= w) {
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            }
            else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    return dp[n][W];
}
```

##### Dyanmic programming with optimized space complexity

```cpp

int knapsack(int W, int wt[], int val[], int n) {

    int dp[W+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i < n + 1; i++) {
        for(int w = W; w >= 0; w--) {

            if (wt[i-1] <= w) {
                // finding the maximum value
                dp[w] = max(dp[w], dp[w-wt[i-1]] + val[i-1]);

            }
        }
    }

    return dp[W];
}

```

#### [Subset sum problem](https://www.geeksforgeeks.org/subset-sum-problem-dp-25/)

##### Using Recursion

```cpp

// taking static values
int dp[1000][1000];
// initialize table to -1 

int subsetSum(int a[], int n, int sum) {

    if(sum == 0) {
        return 1;
    }

    if( n <= 0) {
        return 0;
    }

    if(dp[n-1][sum] != -1) {
        return dp[n-1][sum];
    }

    if(a[n-1] > sum) {
        return dp[n-1][sum] = subsetSum(a, n-1, sum);
    }

    else{
        return dp[n-1][sum] = subsetSum(a, n-1, sum) ||subsetSum(a, n-1, sum - a[n-1]);
    }

}
```

##### Using tabulation

```cpp

// A Dynamic Programming solution
// for subset sum problem
#include <iostream>
using namespace std;

// Returns true if there is a subset of set[]
// with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
	// The value of subset[i][j] will be true if
	// there is a subset of set[0..j-1] with sum
	// equal to i
	bool subset[n + 1][sum + 1];

	// If sum is 0, then answer is true
	for (int i = 0; i <= n; i++)
		subset[i][0] = true;

	// If sum is not 0 and set is empty,
	// then answer is false
	for (int i = 1; i <= sum; i++)
		subset[0][i] = false;

	// Fill the subset table in bottom up manner
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j < set[i - 1])
				subset[i][j] = subset[i - 1][j];
			if (j >= set[i - 1])
				subset[i][j] = subset[i - 1][j]
							|| subset[i - 1][j - set[i - 1]];
		}
	}

	/* // uncomment this code to print table
	for (int i = 0; i <= n; i++)
	{
	for (int j = 0; j <= sum; j++)
		printf ("%4d", subset[i][j]);
	cout <<"\n";
	}*/

	return subset[n][sum];
}

// Driver code
int main()
{
	int set[] = { 3, 34, 4, 12, 5, 2 };
	int sum = 9;
	int n = sizeof(set) / sizeof(set[0]);
	if (isSubsetSum(set, n, sum) == true)
		cout <<"Found a subset with given sum";
	else
		cout <<"No subset with given sum";
	return 0;
}
// This code is contributed by shivanisinghss2110


```

#### [Equal Sum Partition of array](https://www.geeksforgeeks.org/partition-problem-dp-18/)

##### Using recursion

```cpp

// first check total sum of array 
// if sum is odd directly return false
// if sum is even check for subset sum with sum is half the sum of the array

// taking static values
int dp[1000][1000];
// initialize table to -1 

int subsetSum(int a[], int n, int sum) {

    if(sum == 0) {
        return 1;
    }

    if( n <= 0) {
        return 0;
    }

    if(dp[n-1][sum] != -1) {
        return dp[n-1][sum];
    }

    if(a[n-1] > sum) {
        return dp[n-1][sum] = subsetSum(a, n-1, sum);
    }

    else{
        return dp[n-1][sum] = subsetSum(a, n-1, sum) ||subsetSum(a, n-1, sum - a[n-1]);
    }

}
```


##### Using Tabulation

```cpp

// A Dynamic Programming solution
// for subset sum problem
#include <iostream>
using namespace std;

// Returns true if there is a subset of set[]
// with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
	// The value of subset[i][j] will be true if
	// there is a subset of set[0..j-1] with sum
	// equal to i
	bool subset[n + 1][sum + 1];

	// If sum is 0, then answer is true
	for (int i = 0; i <= n; i++)
		subset[i][0] = true;

	// If sum is not 0 and set is empty,
	// then answer is false
	for (int i = 1; i <= sum; i++)
		subset[0][i] = false;

	// Fill the subset table in bottom up manner
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j < set[i - 1])
				subset[i][j] = subset[i - 1][j];
			if (j >= set[i - 1])
				subset[i][j] = subset[i - 1][j]
							|| subset[i - 1][j - set[i - 1]];
		}
	}

	/* // uncomment this code to print table
	for (int i = 0; i <= n; i++)
	{
	for (int j = 0; j <= sum; j++)
		printf ("%4d", subset[i][j]);
	cout <<"\n";
	}*/

	return subset[n][sum];
}

// Driver code
int main()
{
	int set[] = { 3, 34, 4, 12, 5, 2 };
	int sum = 9;
	int n = sizeof(set) / sizeof(set[0]);
	if (isSubsetSum(set, n, sum) == true)
		cout <<"Found a subset with given sum";
	else
		cout <<"No subset with given sum";
	return 0;
}
// This code is contributed by shivanisinghss2110

```

#### [Count of subsets with sum equal to X](https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/)

**Using Recursion Memoization**

```cpp

#include <bits/stdc++.h>

using namespace std; 

int tmp[1001][1001];  


int subset_count(int* arr, int sum, int n) 
{ ` if(sum==0)
        return 1;
    if(n==0)
        return 0;
    if(tmp[n][sum]!=-1)
        return tmp[n][sum];
    else{
        if(arr[n-1]>sum)
            return tmp[n][sum]=subset_count(arr,sum, n-1);
        else{
            return tmp[n][sum]=subset_count(arr,sum, n- 1)+subset_count(arr,sum-arr[n-1], n-1);`
        }
    }
} 

// Driver code 

int main() 
{ 
    memset(tmp,-1,sizeof(tmp));
    int arr[] = { 2, 3, 5, 6, 8, 10 }; 
    int n = sizeof(arr) / sizeof(int); 
    int sum = 10; `


    cout << subset_count(arr,sum, n); 

    return 0; 
}

```

**Using Tabulation**

```cpp

#include <bits/stdc++.h>
using namespace std;
  
int subsetSum(int a[], int n, int sum)
{
    // Initializing the matrix
    int tab[n + 1][sum + 1];
  // Initializing the first value of matrix
    tab[0][0] = 1;
    for (int i = 1; i <= sum; i++)
        tab[0][i] = 0;
    for (int i = 1; i <= n; i++)
        tab[i][0] = 1;
  
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
          // if the value is greater than the sum 
            if (a[i - 1] > j)
                tab[i][j] = tab[i - 1][j];
            else
            {
                tab[i][j] = tab[i - 1][j] + tab[i - 1][j - a[i - 1]];
            }
        }
    }
  
  
    return tab[n][sum];
}
  
int main()
{
    int n = 4;
    int a[] = {3,3,3,3};
    int sum = 6;
  
    cout << (subsetSum(a, n, sum));
}
```

#### Minimum Subset Sum Difference 

```cpp

// Here we need to find the minimum difference between two subsets that can be found
// this problem is similar to subset sum problem
// but here our target sum is half of the sum of the array

// so in subset sum apply dp for the sum (sum is half of array sum) 
// after getting the values in table traverse the table in reverse order and the first
// true value index is the sum of first subset 
// so the minimum difference is
// abs(first subset - second subset)
// i.e abs( (array_sum - first subset) - first subset)
// array_sum - 2 * first subset

// pseudo code for this is

for(int i = sum/2; i >= 0; i--) {
    if (subset[last_row][i] == true) {
        diff = array_sum - (2 * i);
        break;
    }
}

return diff;
}

// complete implementation of the code is

// A Recursive C program to solve minimum sum partition
// problem.
#include <bits/stdc++.h>
using namespace std;

// Returns the minimum value of the difference of the two
// sets.
int findMin(int arr[], int n)
{
	// Calculate sum of all elements
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];

	// Create an array to store results of subproblems
	bool dp[n + 1][sum + 1];

	// Initialize first column as true. 0 sum is possible
	// with all elements.
	for (int i = 0; i <= n; i++)
		dp[i][0] = true;

	// Initialize top row, except dp[0][0], as false. With
	// 0 elements, no other sum except 0 is possible
	for (int i = 1; i <= sum; i++)
		dp[0][i] = false;

	// Fill the partition table in bottom up manner
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			// If i'th element is excluded
			dp[i][j] = dp[i - 1][j];

			// If i'th element is included
			if (arr[i - 1] <= j)
				dp[i][j] |= dp[i - 1][j - arr[i - 1]];
		}
	}

	// Initialize difference of two sums.
	int diff = INT_MAX;

	// Find the largest j such that dp[n][j]
	// is true where j loops from sum/2 t0 0
	for (int j = sum / 2; j >= 0; j--) {
		// Find the
		if (dp[n][j] == true) {
			diff = sum - 2 * j;
			break;
		}
	}
	return diff;
}

// Driver program to test above function
int main()
{
	int arr[] = { 3, 1, 4, 2, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The minimum difference between 2 sets is "
		<< findMin(arr, n);
	return 0;
}

```

**Below is space optimized version only see after completion of all**

```cpp
#include <iostream>
using namespace std;

int minDifference(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	int y = sum / 2 + 1;
	// dp[i] gives whether is it possible to get i as sum of
	// elements dd is helper variable
	// we use dd to ignoring duplicates
	bool dp[y], dd[y];

	// Initialising dp and dd
	for (int i = 0; i < y; i++) {
		dp[i] = dd[i] = false;
	}

	// sum = 0 is possible
	dd[0] = true;
	for (int i = 0; i < n; i++) {
		// updating dd[k] as true if k can be formed using
		// elements from 1 to i+1
		for (int j = 0; j + arr[i] < y; j++) {
			if (dp[j])
				dd[j + arr[i]] = true;
		}
		// updating dd
		for (int j = 0; j < y; j++) {
			if (dd[j])
				dp[j] = true;
			dd[j] = false; // reset dd
		}
	}
	// checking the number from sum/2 to 1 which is possible
	// to get as sum

	for (int i = y - 1; i >= 0; i--) {
		if (dp[i])
			return (sum - 2 * i);
		// since i is possible to form then another number
		// is sum-i
		// so mindifference is sum-i-i
	}
}
int main()
{

	int arr[] = { 1, 6, 11, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The Minimum difference of 2 sets is "
		<< minDifference(arr, n) << '\n';
	return 0;
}
```

#### [Count number of subsets](https://leetcode.com/discuss/interview-question/1271034/count-no-of-subsets-with-given-difference-dp)

**This sum is same as the count number of subset with given sum with bit of maths involved**

Let sum of subset 1 be s1 and subset 2 with s2
s1 - s2 = diff (given)
s1 + s2=sum of array (logical)
Therefore adding both eq we get :
2s1= diff + sum of array
s1= (diff + sum of array)/2;
Problem reduces to find no of subsets with given sum

```cpp
int subsetSum(int a[], int n, int sum)
{
    // Initializing the matrix
    int dp[n + 1][sum + 1];
  // Initializing the first value of matrix
    dp[0][0] = 1;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
        dp[i][0] = 1;
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
          // if the value is greater than the sum
            if (a[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]]; 
            else
                  dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int countWithGivenSum(int arr[ ], int n, int diff)
{   
     int sum=0;
    for(int i=0;i<n;i++)
         sum+=nums[i]
	 
	 int reqSum=(diff+sum)/2;
	 return subsetSum(arr,n,reqSum);
}
```

#### [Target Sum](https://leetcode.com/problems/target-sum/)

**This sum is same as the above one just the explanation is changed**
**By adding symbols + and - will result is two sums say S1 (got by adding all positives) and -S2 (got by adding all negatives) now their sum should be K**

**That is S1 + (-S2) should be k i.e S1 - S2 = k, now this problem is reduces to count subset with given difference which is further reduces to count number of subsets**



#### [Unbounded Knapsack](https://stackoverflow.com/questions/50221844/recursive-solution-of-unbounded-knapsack-using-logic-of-0-1-knapsack)

* Unbounded knapsack is almost similar to the 0/1 knapsack
* only difference is in 0/1 knapsack we are going to consider a item only once 

```cpp
// that is no matter if the item is included in bag or not
// we are not going to call that item again

if (current_weight_of_item <= Weight_of_bag ) {
    return max( val[n-1] + knapsack(weight_array, val_array, Weight_of_bag - weight_array[n-1] , n-1), knapsack(weight_array, val_array, Weight_of_bag, n-1));
}

else{
    return knapsack(weight_array, val_array, Weight_of_bag, n-1);
}

```

* Here we can see that in all the cases we are going to call the function with n-1 which means we have processed the current element

**But in unbounded knapsack if current weight is less that or equal to weight of bag then that can be still included again so it is not completely processed, only if the element is not included then we can treat it as completely processed**

```cpp

if (wt[n-1] <= W) {

    return max( val[n-1] + knapsack(wt, val, W - wt[n-1], n), knapsack(wt, val, W, n-1));
}

else {
    return knapsack(wt, val, W, n);
}

```

* here you can see that in if case when the item is included we are calling the function same with n again
* currently it is in recursive but below is the python implementation for DP of tabulation and Memoization

**Memoization**

```python
def UnboundedKnapSack2(wt, val, n, capacity):
    global dp
    if dp[n][capacity] != -1:
        return dp[n][capacity]
    else:
        if n == 0 or capacity <= 0:
            dp[n][capacity] = 0
            return dp[n][capacity]
        elif wt[n - 1] <= capacity:
            dp[n][capacity] = max(
                val[n - 1] + UnboundedKnapSack(wt, val, n, capacity - wt[n - 1]),
                UnboundedKnapSack(wt, val, n - 1, capacity),
            )
            return dp[n][capacity]
        else:
            dp[n][capacity] = UnboundedKnapSack(wt, val, n - 1, capacity)
            return dp[n][capacity]

weight = [1, 3, 4, 5]
values = [10, 40, 50, 70]
capacity = 8
dp = [[-1 for i in range(capacity + 1)] for j in range(len(weight) + 1)]
print(UnboundedKnapSack2(weight, values, len(weight), capacity))

```

**Tabulation**

```python

def UnboundedKnapSack3(wt, val, capacity):
    n = len(wt)
    dp = [[0 for i in range(capacity + 1)] for j in range(n + 1)]
    for i in range(n + 1):
        for j in range(capacity + 1):
            if i == 0 or j == 0:
                dp[i][j] = 0
            elif j >= wt[i - 1]:
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j])
            else:
                dp[i][j] = dp[i - 1][j]
    return dp[-1][-1]


print(UnboundedKnapSack3([1, 3, 4, 5], [10, 40, 50, 70], 8))

```

#### Our next question is Rod Cutting problem which is just the other name of unbounded knapsack
#### [here there is approach is GFG where instead of using 2D array they are using 1D array which is space optimized after completion of everything try to understand the main intuition behind the approach](https://www.geeksforgeeks.org/cutting-a-rod-dp-13/)


#### [Coin Change Max number of ways](https://www.geeksforgeeks.org/cutting-a-rod-dp-13/)

* Coin change is just like the number of subset sum problem but it is the version of knapsack

**Memoized version**

```cpp

vector<vector<long>> dp(1000, vector<long>(1000));
 
 long answer(vector<long>& array, int sum, int n){
     
     if(sum == 0) {
         return 1;
     }
     
     if (n == 0) {
         return 0;
     }
     
     if (dp[n][sum] != -1) {
         return dp[n][sum];
     }
     
     if (array[n-1] <= sum) {
         return dp[n][sum] = answer(array, sum, n-1) + answer(array, sum - array[n-1], n);
     }
     
     else {
         return dp[n][sum] = answer(array, sum, n-1);
     }
 }

long getWays(int n, vector<long> c) {
    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) {
            dp[i][j] = -1;
        }
    }
    return answer(c, n, c.size());
}

```


**Tabulation Method**

```cpp

vector<vector<long>> dp(1000, vector<long>(1000));
 
 long answer(vector<long>& array, int sum, int n){
     
     for(int i = 0; i <= array.size(); i++) {
         dp[i][0] = 1;
     }
     
     for(int i = 1; i <= sum; i++) {
         dp[0][i] = 0;
     }
     
     
     for(int i = 1; i <= array.size(); i++) {
         for(int j = 1; j <= sum; j++) {
             
             if (array[i-1] <= j){
                 dp[i][j] = dp[i-1][j] + dp[i][j - array[i-1]];
             }
             
             else {
                 dp[i][j] = dp[i-1][j];
             }
         }
     }
     
     return dp[n][sum];
 }

long getWays(int n, vector<long> c) {
    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) {
            dp[i][j] = -1;
        }
    }
    return answer(c, n, c.size());
}

```


#### [Minimum Number of Coins Required to get the sum](https://leetcode.com/problems/coin-change/)


##### Recursive Brute Force Solution

```cpp

class Solution {
public:
    int recursion(vector<int> wt, int w, int n)
    {
        if (n == 0 || w == 0)
            return (w == 0) ? 0 : INT_MAX - 1;
        
        if (wt[n - 1] > w) 
            return recursion(wt, w , n - 1);
        else 
            return min(recursion(wt, w, n - 1), 1 + recursion(wt, w - wt[n - 1], n));
    }
    
    int coinChange(vector<int>& coins, int amount) 
    {
        int minCoins = recursion(coins, amount, coins.size());
        return minCoins == INT_MAX - 1 ? -1 : minCoins;    
    }
};

```

##### Memoization 

```cpp

class Solution {
public:
    int dp[10000 + 1][12 + 1];
    
    int memoization(vector<int>& wt, int w, int n)
    {
        if (n == 0 || w == 0)
            return (w == 0) ? 0 : INT_MAX - 1;
        
        if (dp[w][n] != -1)
            return dp[w][n];
			
        if (wt[n - 1] > w) 
            return dp[w][n] = memoization(wt, w, n - 1);
        else 
            return dp[w][n] = min(memoization(wt, w, n - 1), 1 + memoization(wt, w - wt[n - 1], n));
    }
    
    int coinChange(vector<int>& coins, int amount) 
    {
        memset(dp, -1, sizeof(dp));
        int minCoins = memoization(coins, amount, coins.size());
        return minCoins == INT_MAX - 1 ? -1 : minCoins;    
    }
};

```

##### Tabulation using 2d Array

```cpp

class Solution {
public:
    int dp[12 + 1][10000 + 1];
    
    int tabulation(vector<int> wt, int w, int n)
    {
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= w; j++){
                if (i == 0 || j == 0) {
                    dp[i][j] = (j == 0) ? 0 : INT_MAX - 1;
                }
            }
        }
        
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < w+1; j++) {
                
                if (wt[i-1] <= j) {
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-wt[i-1]]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        
        return dp[n][w];
    }
    
    int coinChange(vector<int>& coins, int amount) 
    {
        memset(dp, -1, sizeof(dp));
        int minCoins = tabulation(coins, amount, coins.size());
        return minCoins == INT_MAX - 1 ? -1 : minCoins;    
    }
};

```



##### Tabulation Method

```cpp

    int coinChange(vector<int>& coins, int amount) {
        
        vector<long> dp(amount+1, INT_MAX);
        
        dp[0] = 0;
        
        for(int i = 1; i <= amount; i++) {
            // iterating through the coins
            for(auto x: coins) {  
                // if current sum - current coin is > 0 then current value is min of both               
                if (i-x >= 0) {
                    dp[i] = min(dp[i], dp[i-x] + 1);
                }
            }
        }
        
        return dp[amount] == INT_MAX? -1: (int)dp[amount];
        
    }

```

#### Longest Common Subsequence Recursive

##### [Solution](https://www.youtube.com/watch?v=4Urd0a0BNng&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=19)

```cpp

/* A Naive recursive implementation of LCS problem */
#include <bits/stdc++.h>
using namespace std;

int max(int a, int b);

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )
{
	if (m == 0 || n == 0)
		return 0;
	if (X[m-1] == Y[n-1])
		return 1 + lcs(X, Y, m-1, n-1);
	else
		return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
	return (a > b)? a : b;
}

/* Driver code */
int main()
{
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";
	
	int m = strlen(X);
	int n = strlen(Y);
	
	cout<<"Length of LCS is "<< lcs( X, Y, m, n ) ;
	
	return 0;
}

// This code is contributed by rathbhupendra

```





# Extra Sums

#### [For the given array print all the possible permutations](https://leetcode.com/problems/permutations/)

#### [Solution 1](https://www.youtube.com/watch?v=YK78FU5Ffjw&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=51)

```cpp

class Solution {
private:
    void recurPermute(vector<int>& ds, vector<int>& nums, vector<vector<int>>& ans, int freq[]) {
    
    // if ds == to num array then all numbers have been added to 
    // the vector so push to final vector
    if (ds.size() == nums.size()){
        ans.push_back(ds);
        return;
    }
    
    for(int i = 0; i < nums.size(); i++) {
        // iterate through the nums array 
        // and check which element is not added yet
        // if freq[i] != 0
        if(!freq[i] ){
            // add element to current vector
            ds.push_back(nums[i]);
            // mark it as added
            freq[i] = 1;
            
            // now again call the recursive function
            recurPermute(ds, nums, ans, freq);
            
            // unmark the element
            freq[i] = 0;
            // remove the element from the current array
            ds.pop_back();
        }
    }
    
    
}
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        // for storing the final answer
        vector<vector<int>> ans;
        // for storing individual vector
        vector<int> ds;
        
        // to keep track of which elements have been added
        // based on their index
        int freq[nums.size()];
        
        // initializing to zero
        for(int i = 0; i < nums.size(); i++) freq[i] = 0;
        
        // calling the actual recursive function
        recurPermute(ds, nums, ans, freq);
        
        return ans;
    }
};

```

#### [Solution 2 with better space complexity](https://youtu.be/f2ic2Rsc9pU?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma)


```cpp

#include<bits/stdc++.h>
using namespace std;

// backtracking method
void recurPermutations(int index, vector<int>& nums, vector<vector<int>>& answer) {

    // if reached end of nums vector add nums to answer vector
    if (index == nums.size()){
        answer.push_back(nums);
        return;
    }

    // traversing the nums array from index position
    for(int i = index; i < nums.size(); i++) {

        // swapping current position with index position
        swap(nums[i], nums[index]);
        // calling the method with next index
        recurPermutations(index+1, nums, answer);   

        // swapping back to the original positions
        swap(nums[i], nums[index]);
    }
}

vector<vector<int>> permutations(vector<int>& nums) {

    // for storing the answer;
    vector<vector<int>> answer;
    // for storing the starting point of loop
    int index  = 0;

    recurPermutations(index, nums, answer);

    return answer;
}


int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) cin >> nums[i];

    vector<vector<int>> answer = permutations(nums);

    for(int i = 0; i < answer.size(); i++) {
        for(int j = 0; j < answer[0].size(); j++) {
            cout << answer[i][j] ;
        }
        cout << endl;
    }

}

```

