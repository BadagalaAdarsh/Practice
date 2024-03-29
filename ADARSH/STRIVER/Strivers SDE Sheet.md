# My Coding Notes

## Coding Questions and Answers

#### [In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:](https://leetcode.com/problems/pascals-triangle/)

#### [Solution with better time for nth row](https://youtu.be/6FLvhQjZqvM?list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&t=311)


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


#### for directly nth row one can use the formula nCr
#### that is for 5th row it will be 4C0 4C1 4C2 4C3 4C4
```cpp

int res = 1;

// below i have assmed n = 5 that is for 5th row

for(int i = 0; i < 5; i++) {

    if (i == 0) {
        cout << 1 << " ";
        continue;
    }

    res *= (n-i);
    res /= i;

    cout << res << " " ;
}


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
highâ€“;
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


#### [Inversion Of Array](https://www.geeksforgeeks.org/counting-inversions/)

#### [Video Solution](https://www.youtube.com/watch?v=kQ1mJlwW-c0&t=0s)

```cpp

/* This funt merges two sorted arrays
and returns inversion count in the arrays.*/
int merge(int arr[], int temp[], int left, int mid,
          int right)
{
    int i, j, k;
    int inv_count = 0;
 
    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
 
            /* this is tricky -- see above
            explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i);
        }
    }
 
    /* Copy the remaining elements of left subarray
(if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    /* Copy the remaining elements of right subarray
       (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];
 
    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}
 

/* An auxiliary recursive function
  that sorts the input array and
returns the number of inversions in the array. */
int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {
        /* Divide the array into two parts and
        call _mergeSortAndCountInv()
        for each of the parts */
        mid = (right + left) / 2;
 
        /* Inversion count will be sum of
        inversions in left-part, right-part
        and number of inversions in merging */
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
 
        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

int main() {

    int arr[] = {5, 3, 2, 4, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int temp[n];
    int ans = _mergeSort(arr, temp, 0, array_size - 1);

    cout << "number of inversions are " << ans;
    return 0;

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

#### Java code easy to understand

```java

public class Solution {
        public boolean searchMatrix(int[][] matrix, int target) {
            if (matrix == null || matrix.length == 0) {
                return false;
            }
            int start = 0, rows = matrix.length, cols = matrix[0].length;
            int end = rows * cols - 1;
            while (start <= end) {
                int mid = (start + end) / 2;
                if (matrix[mid / cols][mid % cols] == target) {
                    return true;
                } 
                if (matrix[mid / cols][mid % cols] < target) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            return false;
        }
    }
    
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
* The majority element is the element that appears more than âŒŠn / 2âŒ‹ times. You may assume that the majority element always exists in the array.


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

* Given an integer array of size n, find all elements that appear more than âŒŠ n/3 âŒ‹ times.

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

#### [Unique Paths](https://leetcode.com/problems/unique-paths/)


#### Recursive Solution (not optimal time complexity is exponential)

```cpp

int countPaths(int i, int j, int n, int m) {

    if ( i== (n-1) && j == (m-1)) return 1;
    if ( i >= n || j >= m) return 0;

    else return countPaths( i+1, j) + countPaths(i, j+1);

}

```

#### Using DP

```cpp

int countPaths(int i, int j, int n, int m, vector<vector<int>>& dp) {
    if (i==(n-1) && j == (m-1)) return 1;
    if (i >= n || j >= m) return 0;

    if (dp[i][j] != -1) return dp[i][j];
    else return dp[i][j] = countPaths(i+1, j, dp) + countPaths(i, j+1, dp);
}

```

### [Most optimal Solution Using Combinatrics](https://www.youtube.com/watch?v=t_f0nwwdg5o&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=18)

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        // its a combinatrics solution
        // answer nCr
        
        int N = n + m -2;
        int r = m - 1;
        double res = 1;
        
        for(int i = 1; i <= r; i++) {
            res = res * ( N- r+ i) / i;
        }
        
        return (int)res;
        
    }
};
```


#### [Reverse Pairs](https://leetcode.com/problems/reverse-pairs/)

* Given an integer array nums, return the number of reverse pairs in the array.

* A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

#### [Nice blog to know about recurrence relation ships](https://leetcode.com/problems/reverse-pairs/discuss/97268/General-principles-behind-problems-similar-to-%22Reverse-Pairs%22)

#### [Video Solution](https://youtu.be/S6rsAlj_iB4?list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2)

```cpp


class Solution {


    int merge(vector<int>& nums, int low, int mid, int high) {
        
        int cnt = 0;
        int j = mid + 1; 
        for(int i = low;i<=mid;i++) {
            while(j<=high && nums[i] > 2LL * nums[j]) {
                j++;
            }
            cnt += (j - (mid+1));
        }
        vector<int> temp; 
        int left = low, right = mid+1; 
        while(left <= mid && right<=high) {
            if(nums[left]<=nums[right]) {
                temp.push_back(nums[left++]); 
            }
            else {
                temp.push_back(nums[right++]); 
            }
        }
        
        // fill all the left part if left
        while (left <= mid) {
            temp.push_back(nums[left++]);
        }
        
        // filling the right part
        while(right <= high) {
            temp.push_back(nums[right++]);
        }
        
        // filling the nums array back
        for(int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
        
        return cnt;
    }
    
    
    
    int mergeSort(vector<int>& nums, int low, int high) {
        
        if(low>=high) return 0; 
        int mid = (low + high) / 2;
        int inv = mergeSort(nums, low, mid); 
        inv += mergeSort(nums, mid+1, high); 
        inv += merge(nums, low, mid, high); 
        return inv; 
    }

public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() -1);
    }
};

```

#### [Two Sum](https://leetcode.com/problems/two-sum/)

* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
* You may assume that each input would have exactly one solution, and you may not use the same element twice.
* You can return the answer in any order

#### [Video Solution](https://www.youtube.com/watch?v=dRUpbt8vHpo&list=PLgUwDviBIf0rVwua0kKYlsS_ik_1lyVK_&index=2)


```cpp

class Solution {
public:


vector<int> twoSum(vector<int> &numbers, int target)
{
	unordered_map<int, int> hash;
	vector<int> result;
	for (int i = 0; i < numbers.size(); i++) {
		int numberToFind = target - numbers[i];

		if (hash.find(numberToFind) != hash.end()) {

			result.push_back(hash[numberToFind]);
			result.push_back(i);			
			return result;
		}

            //number was not found. Put it in the map.
		hash[numbers[i]] = i;
	}
	return result;
}
};

```

#### [4 Sum](https://leetcode.com/problems/4sum/)

#### [Video Solution](https://www.youtube.com/watch?v=4ggF3tXIAp0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=22)


```cpp


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& num, int target) {
        vector<vector<int> > res;
        
        if (num.empty())
            return res;
        int n = num.size(); 
        sort(num.begin(),num.end());
    
        for (int i = 0; i < n; i++) {
        
            int target_3 = target - num[i];
        
            for (int j = i + 1; j < n; j++) {
            
                int target_2 = target_3 - num[j];
            
                int front = j + 1;
                int back = n - 1;
            
                while(front < back) {
                
                    int two_sum = num[front] + num[back];
                
                    if (two_sum < target_2) front++;
                
                    else if (two_sum > target_2) back--;
                
                    else {
                    
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = num[i];
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[front];
                        quadruplet[3] = num[back];
                        res.push_back(quadruplet);
                    
                        // Processing the duplicates of number 3
                        while (front < back && num[front] == quadruplet[2]) ++front;
                    
                        // Processing the duplicates of number 4
                        while (front < back && num[back] == quadruplet[3]) --back;
                
                    }
                }
                
                // Processing the duplicates of number 2
                while(j + 1 < n && num[j + 1] == num[j]) ++j;
            }
        
            // Processing the duplicates of number 1
            while (i + 1 < n && num[i + 1] == num[i]) ++i;
        
        }
    
        return res;
    }
};

```

#### [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)


#### [Video Solution](https://youtu.be/qgizvmgeyUM?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma)


```cpp

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int> hashset;
        
        for(auto num: nums) {
            hashset.insert(num);
        }
        
        int longestStreak = 0;
        
        for(int num: nums) {
            
            // check for one less number
            if (!hashset.count(num-1)) {
                int currentNum = num;
                int currentStreak = 1;
                
                while(hashset.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }
                
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        
        return longestStreak;
    }
};

```


#### [Longest Sub Array with 0 sum](https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1)



```cpp

int maxLen(int A[], int n)
{
    // Your code here
    unordered_map<int,int> mpp; 
    int maxi = 0;
    int sum = 0; 
    for(int i = 0;i<n;i++) {
        sum += A[i]; 
        if(sum == 0) {
            maxi = i + 1; 
        }
        else {
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]); 
            }
            else {
                mpp[sum] = i;
            }
        }
        
    }
    return maxi; 
}

```


#### [count sub arrays with XOR is k](https://www.interviewbit.com/problems/subarray-with-given-xor/)

#### [video Solution](https://youtu.be/lO9R5CaGRPY?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma)

```cpp

int Solution::solve(vector<int> &A, int B) {

    map<int,int> freq;

    int count = 0;
    int xorr = 0;

    for(auto it: A) {
        xorr = xorr ^ it;

        if (xorr == B) {
            count++;
        }

        if (freq.find(xorr ^ B) != freq.end()) {
            count += freq[xorr ^ B];
        }

        freq[xorr] += 1;
    }

    return count;
}

```

#### [Longest substring without repeating](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

#### [Video Solution](https://www.youtube.com/watch?v=qtVh-XEpsJo&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=26)

```cpp

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        set<char> visited;
        
        int left = 0, right =  0, n = s.size(), ans = 0;
        
        while(left < n && right < n) {
            
            if (visited.find(s[right]) == visited.end()) {
                visited.insert(s[right]);
                right++;
                
                ans = max(ans , right - left);
            }
            
            else{
                visited.erase(s[left]);
                left++;
            }
        }
        
        return ans;
    }
};

```

#### [Reverse a linked list](https://leetcode.com/problems/reverse-linked-list/)

 #### [Video Solution](https://youtu.be/iRtLEoL-r-g?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma)

 ```cpp

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;
        
        while(head != NULL) {
            ListNode* next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        
        return  newHead;
    }
};

```

#### [Find middle of linked list](https://leetcode.com/problems/middle-of-the-linked-list/)

#### [Video Solution](https://www.youtube.com/watch?v=sGdwSH8RK-o&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=28)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        ListNode* slow = head, *fast = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};

```


#### [Merge Two sorted linked list](https://leetcode.com/problems/merge-two-sorted-lists/)

#### [Video Solution](https://www.youtube.com/watch?v=Xb4slcp1U38&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=29)


```cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* res = new ListNode();
        ListNode* temp = res;
        
        while(l1 != NULL && l2 != NULL) {
            
            if (l1->val < l2 ->val) {
                res->next = l1;
                res = res->next;
                l1 = l1->next;
            }
            
            else{
                res->next = l2;
                res = res->next ;
                l2 = l2->next;
            }
        }
        
        while(l1 != NULL) {
            res->next = l1;
            res = res->next;
            l1 = l1->next;
        }
        
        while(l2 != NULL) {
            res->next = l2;
            res = res->next;
            l2 = l2->next;
        }
        
        return temp->next;
    }
};

```

#### Space optimised version (in place)

```cpp

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}

class Solution{

public:
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {

        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        if (l1->val > l2->val) std::swap(l1, l2);

        ListNode* res = l1;

        while(l1 != NULL && l2 != NULL) {

            ListNode* temp = NULL;

            while(l1 != NULL && l1->val <= l2->val) {
                temp = l1;
                l1 = l1->next;
            }

            temp->next = l2;
            std::swap(l1, l2);
        }

        return res;
    }
};

```


#### [Remove Nth node from back of linked list](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)


#### [Video Solution](https://www.youtube.com/watch?v=Lhu3MsXZy-Q&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=30)


```cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* start = new ListNode();
        start->next = head;
        
        ListNode* fast = start;
        ListNode* slow = start;
        
        for(int i = 1; i <= n; i++) {
            fast = fast->next;
        }
        
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return start->next;
        
    }
};

```


#### [Add two numbers as linked list](https://leetcode.com/problems/add-two-numbers/)


#### [video solution](https://youtu.be/LBVsXSMOIk4?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma)

```cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        
        int carry = 0;
        
        while(l1 != NULL || l2 != NULL || carry) {
            
            int sum = 0;
            
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != NULL ){
                sum += l2->val;
                l2 = l2->next;
            }
            
            sum += carry;
            carry = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            
            temp->next = node;
            temp = temp->next;
            
        }
        
        return dummy->next;
        
    }
};

```


#### [Delete Node in linkedlist when pointer to that node is given (in order of 1 time)](https://leetcode.com/problems/delete-node-in-a-linked-list/)

#### [Video Solution](https://youtu.be/icnp4FJdZ_c?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma)


```cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
     
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

```


#### [Find intersection point of two linkedlist](https://leetcode.com/problems/intersection-of-two-linked-lists/)

#### [Video Solution](https://www.youtube.com/watch?v=u4FWXfgS8jw&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=33)


```cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if (headA == NULL || headB == NULL ) return NULL;
        
        ListNode* a = headA;
        ListNode* b = headB;
        
        // if a & b have different lengths then we will stop loop after second iteration
        while( a!= b) {
            
            // for the end of first iteration, we just reset the pointer to the head of 
            // another linked list
            
            a = a==NULL? headB : a->next;
            b = b==NULL ? headA : b->next;
        }
        
        return a;
        
    }
};

```

#### [Detect cycle in linkedlist](https://leetcode.com/problems/linked-list-cycle/)

#### [Video solution](https://www.youtube.com/watch?v=354J83hX7RI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=34)


```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if (head == NULL || head->next == NULL) return false;
        
        ListNode* fast = head;
        ListNode* slow =  head;
        
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            
            if (fast == slow){
                return true;
            }
        }
        
        return false;
    }
};

```

#### [Reverse a LinkedList in groups of size k.](https://leetcode.com/problems/reverse-nodes-in-k-group/)

#### [Video solution must watch again](https://youtu.be/Of0HPkk3JgI?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma)


```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == NULL || k == 1) return head;
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* cur = dummy, *nex = dummy, *pre = dummy;
        
        int count = 0;
        
        while(cur->next != NULL) {
            cur = cur->next;
            count++;
        }
        
        while(count >= k) {
            
            cur = pre->next;
            nex = cur->next;
            
            for(int i = 1; i < k; i++) {
                
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            
            pre = cur;
            count -= k;
        }
        
        return dummy->next;
        
    }
};
```

#### [Check if a linked list is palindrome or not](https://leetcode.com/problems/palindrome-linked-list/)

#### [Video Solution](https://youtu.be/-DtNInqFUXs?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        if (head == NULL || head->next == NULL) return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverseList(slow->next);
        slow = slow->next;
        
        while(slow != NULL) {
            if (head->val != slow->val) {
                return false;
            }
            
            head = head->next;
            slow = slow->next;
        }
        
        return true;
      
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* next = NULL;
        
        while(head != NULL ) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        
        return pre;
    }
};
```


#### [Find the starting point of the cycle in the linked list](https://leetcode.com/problems/linked-list-cycle-ii/)


#### [Video Solution](https://youtu.be/QfbOhn0WZ88?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma)

```cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if (head == NULL || head->next == NULL) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;
        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                while(slow != entry) {
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }            
            
        }
        return NULL;
    }
};

```

#### [Flattening of a linkedlist](https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1)

#### [Video Solution](https://www.youtube.com/watch?v=ysytSSXpAI0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=39)


```cpp

Node* mergeTwoLists(Node* a, Node* b) {
    
    Node *temp = new Node(0);
    Node *res = temp; 
    
    // below code is just merge sort applied on two linked list
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->bottom = a; 
            temp = temp->bottom; 
            a = a->bottom; 
        }
        else {
            temp->bottom = b;
            temp = temp->bottom; 
            b = b->bottom; 
        }
    }
    
    if(a) temp->bottom = a; 
    else temp->bottom = b; 
    
    return res -> bottom; 
    
}
Node *flatten(Node *root)
{
   
        if (root == NULL || root->next == NULL) 
            return root; 
  
        // recur for list on right 
        root->next = flatten(root->next); 
  
        // now merge 
        root = mergeTwoLists(root, root->next); 
  
        // return the root 
        // it will be in turn merged with its left 
        return root; 
}

```

#### [Rotate a linked list](https://leetcode.com/problems/rotate-list/description/)

#### [Video Solution](https://youtu.be/9VPm6nEbVPA?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma)


```cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // edge cases 
        if (head == NULL || head->next == NULL || k == 0) return head;
        
        // compute the length
        ListNode *cur = head;
        int len = 1;
        while (cur->next ) { 
            cur = cur->next;
            len++;
        }
        
        // go till that node
        cur->next = head;
        k = k % len; 
        k = len - k;
        while (k--) cur = cur->next;
        
        // make the node head and break connection 
        head = cur->next;
        cur->next = NULL;
        
        
        return head; 
    }
};

```

#### [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/)

#### [Video Solution](https://www.youtube.com/watch?v=VNf6VynfpdM)

```cpp

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *iter = head; 
          Node *front = head;

          // First round: make copy of each node,
          // and link them together side-by-side in a single list.
          while (iter != NULL) {
            front = iter->next;

            Node *copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;

            iter = front;
          }

          // Second round: assign random pointers for the copy nodes.
          iter = head;
          while (iter != NULL) {
            if (iter->random != NULL) {
              iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
          }

          // Third round: restore the original list, and extract the copy list.
          iter = head;
          Node *pseudoHead = new Node(0);
          Node *copy = pseudoHead;

          while (iter != NULL) {
            front = iter->next->next;

            // extract the copy
            copy->next = iter->next;

            // restore the original list
            iter->next = front;
              
            copy = copy -> next; 
            iter = front;
          }

          return pseudoHead->next;
    }
};
```

#### [3 Sum](https://leetcode.com/problems/3sum/)

#### [Video Solution](https://www.youtube.com/watch?v=onLoX6Nhvmg&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=42)

```cpp

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int>> res; 
        sort(num.begin(), num.end()); 
        
        // moves for a
        for (int i = 0; i < (int)(num.size())-2; i++) {
            
            if (i == 0 || (i > 0 && num[i] != num[i-1])) {
                
                int lo = i+1, hi = (int)(num.size())-1, sum = 0 - num[i];
                
                while (lo < hi) {
                    if (num[lo] + num[hi] == sum) {
                        
                        vector<int> temp; 
                        temp.push_back(num[i]); 
                        temp.push_back(num[lo]); 
                        temp.push_back(num[hi]); 
                        res.push_back(temp);
                        
                        while (lo < hi && num[lo] == num[lo+1]) lo++;
                        while (lo < hi && num[hi] == num[hi-1]) hi--;
                        
                        lo++; hi--;
                    } 
                    else if (num[lo] + num[hi] < sum) lo++;
                    else hi--;
               }
            }
        }
        return res;
    }
};

```



#### [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)

#### [Video Solution](https://youtu.be/m18Hntz4go8?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma)

```cpp


class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size(); 
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        
        while(left<=right){
            
            if(height[left]<=height[right]){

                if(height[left]>=maxleft) maxleft=height[left];
                else res+=maxleft-height[left];
                
                left++;
            }
            else{

                if(height[right]>=maxright) maxright= height[right];
                else res+=maxright-height[right];
                
                right--;
            }
        }
        return res;
    }
};

```


#### [Remove Duplicate from sorted array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

#### [Video Solution](https://www.youtube.com/watch?v=Fm_p9lJ4Z_8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=44)

```cpp

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) 
            return 0;
        
        int i = 0;
        
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        
        return i + 1;
    }
};

```

#### [Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/)


```cpp


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int maxi = 0;
        for(int i = 0;i<nums.size();i++) {
            if(nums[i] == 1) {
                cnt++; 
            }
            else {
                cnt = 0; 
            }
            
            maxi = max(maxi, cnt); 
        }
        return maxi; 
    }
};

```

#### [N meetings in one room](https://www.geeksforgeeks.org/find-maximum-meetings-in-one-room/)

#### [Video Solution](https://www.youtube.com/watch?v=II6ziNnub1Q&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=46)

```cpp

struct meeting {
    int start;
    int end;
    int pos; 
}; 
bool comparator(struct meeting m1, meeting m2) 
{ 
    if (m1.end < m2.end) return true; 
    else if(m1.end > m2.end) return false; 
    else if(m1.pos < m2.pos) return true; 
    return false; 
} 
void maxMeetings(int s[], int e[], int n) {
    struct meeting meet[n]; 
    for(int i = 0;i<n;i++) {
        meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i+1; 
    }
    
    sort(meet, meet+n, comparator); 
    
    vector<int> answer;
    
    int limit = meet[0].end; 
    answer.push_back(meet[0].pos); 
    
    for(int i = 1;i<n;i++) {
        if(meet[i].start > limit) {
            limit = meet[i].end; 
            answer.push_back(meet[i].pos); 
        }
    }
    for(int i = 0;i<answer.size();i++) {
        cout << answer[i] << " "; 
    }
    
}

```

#### [Minimum platforms needed](https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#)

#### [Video Solution](https://youtu.be/dxVcMDI7vyI?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma)


```cpp

int findPlatform(int arr[], int dep[], int n)
{
	sort(arr, arr+n); 
	sort(dep, dep+n); 
	
	int plat_needed = 1, result = 1; 
    int i = 1, j = 0; 
 
    while (i < n && j < n) { 
        if (arr[i] <= dep[j]) { 
            plat_needed++; 
            i++; 
        } 
  
        else if (arr[i] > dep[j]) { 
            plat_needed--; 
            j++; 
        } 
 
        if (plat_needed > result) 
            result = plat_needed; 
    } 
  
    return result; 
}

```

#### [Job Sequencing Problem](https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#)
#### [Video Solution](https://www.youtube.com/watch?v=LjPx4wQaRIs&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=48)

```cpp

// Prints minimum number of platforms reqquired 
// This function is used for sorting all jobs according to profit 
bool comparison(Job a, Job b) 
{ 
     return (a.profit > b.profit); 
} 
pair<int,int> JobScheduling(Job arr[], int n) 
{ 
    
    sort(arr, arr + n, comparison); 
    int maxi = arr[0].dead;
    for(int i = 1;i<n;i++) {
        maxi = max(maxi, arr[i].dead); 
    }
    
    int slot[maxi + 1];   
  
    for (int i=0; i<=maxi; i++) 
        slot[i] = -1; 
        
    int countJobs = 0, jobProfit = 0;
  
    for (int i=0; i<n; i++) 
    { 
       for (int j=arr[i].dead; j>0; j--) 
       { 
          if (slot[j]==-1) 
          { 
            slot[j] = i; 
            countJobs++; 
            jobProfit+=arr[i].profit;
            break; 
          } 
       } 
    } 
    
    return make_pair(countJobs, jobProfit); 
} 

```

#### [Fractional Knapsack](https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1)
#### [Video Solution](https://www.youtube.com/watch?v=F_DDzYnxO14&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=49)


```cpp

bool comp(Item a, Item b) {
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2; 
}
// function to return fractionalweights
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    
    sort(arr, arr + n, comp); 
    
    int curWeight = 0; 
    double finalvalue = 0.0; 
 
    
    for (int i = 0; i < n; i++) {
       
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }
 

        else {
            int remain = W - curWeight;
            finalvalue += (arr[i].value / (double)arr[i].weight) * (double)remain;
            break;
        }
    }
 
    return finalvalue;
    
}

```


#### [Find minimum number of coins that make a given value](https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/)

#### [Video Solution](https://www.youtube.com/watch?v=mVg9CfJvayM&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=48)

#### [Video of aditya varma which used 2d array but easy to understand as you know this algo earlier](https://www.youtube.com/watch?v=I-l6PBeERuc)

```cpp

// A Dynamic Programming based C++ program to find minimum of coins
// to make a given change V
#include<bits/stdc++.h>
using namespace std;

// m is size of coins array (number of different coins)
int minCoins(int coins[], int m, int V)
{
	// table[i] will be storing the minimum number of coins
	// required for i value. So table[V] will have result
	int table[V+1];

	// Base case (If given value V is 0)
	table[0] = 0;

	// Initialize all table values as Infinite
	for (int i=1; i<=V; i++)
		table[i] = INT_MAX;

	// Compute minimum coins required for all
	// values from 1 to V
	for (int i=1; i<=V; i++)
	{
		// Go through all coins smaller than i
		for (int j=0; j<m; j++)
		if (coins[j] <= i)
		{
			int sub_res = table[i-coins[j]];
			if (sub_res != INT_MAX && sub_res + 1 < table[i])
				table[i] = sub_res + 1;
		}
	}

	if(table[V]==INT_MAX)
		return -1;

	return table[V];
}

// Driver program to test above function
int main()
{
	int coins[] = {9, 6, 5, 1};
	int m = sizeof(coins)/sizeof(coins[0]);
	int V = 11;
	cout << "Minimum coins required is "
		<< minCoins(coins, m, V);
	return 0;
}
```

#### [Subset Sums](https://practice.geeksforgeeks.org/problems/subset-sums2234/1#)
#### [Video Solution](https://www.youtube.com/watch?v=rYkfBRtMJr8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=54)


```cpp


public: 
    void func(int ind, int sum,vector<int> &arr, int N, vector<int> &sumSubset) {
        if(ind == N) {
            sumSubset.push_back(sum); 
            return; 
        }
        
        // pick the element 
        func(ind + 1, sum + arr[ind], arr, N, sumSubset); 
        
        // Do-not pick the element
        func(ind + 1, sum, arr, N, sumSubset);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> sumSubset; 
        func(0, 0, arr, N, sumSubset);
        sort(sumSubset.begin(), sumSubset.end());
        return sumSubset;
    }

```


#### [Create all posibble subsets](https://leetcode.com/problems/subsets/)

#### My solution using basic recursion and backtracking

```cpp
class Solution {
private:
    void function(int start, int end, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        
        if(start == end) {
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[start]);
        function(start+1, end, nums, temp, ans);
        temp.pop_back();
        function(start+1, end, nums, temp, ans);
        
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        vector<int> temp;
        function(0, nums.size(), nums, temp, ans);
        
        return ans;
    }
};

```

#### Recursion using for loop

```cpp

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        subsets(nums, 0, sub, subs);
        return subs;
    }
private:
    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int j = i; j < nums.size(); j++) {
            sub.push_back(nums[j]);
            subsets(nums, j + 1, sub, subs);
            sub.pop_back();
        }
    }
};

```


#### [subset II print only unique subsets](https://leetcode.com/problems/subsets-ii/)

#### [Video Solution](https://youtu.be/RIn3gOkbhQE?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma)

```cpp

class Solution {
    
private:
    void findSubsets(int start, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans){
        ans.push_back(ds);
        
        for(int i = start; i < nums.size(); i++){
            
            if (i!= start && (nums[i] == nums[i-1])) continue;
            
            ds.push_back(nums[i]);
            findSubsets(i+1, nums, ds, ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        sort(nums.begin(), nums.end());
        findSubsets(0, nums, ds, ans);
        
        return ans;
    }
};

```

#### [Combination Sum](https://leetcode.com/problems/combination-sum/)
#### [Video Solution](https://youtu.be/OyZFFqQtu98?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma)


```cpp

class Solution {
    
private:
    void getCombinations(int start, vector<int>& candidates, int target, vector<int>& ds, vector<vector<int>>& ans){
        
        if (target == 0){
            ans.push_back(ds);
            return;
        }
        
        if (start == candidates.size()){
            
            return;
        }
        
        if (candidates[start] <= target){
            ds.push_back(candidates[start]);
            getCombinations(start, candidates, target - candidates[start], ds, ans);
            ds.pop_back();
        }
        
        getCombinations(start+1, candidates, target, ds, ans);
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        getCombinations(0, candidates, target, ds, ans);
        
        return ans;
    }
};

```

#### [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/)
#### [Video Solution](https://youtu.be/G1fRTGRxXU8?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma)

```cpp
class Solution {
    public: 
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int>&ds) {
        if(target==0) {
            ans.push_back(ds);
            return;
        }        
        for(int i = ind;i<arr.size();i++) {
            if(i>ind && arr[i]==arr[i-1]) continue; 
            if(arr[i]>target) break; 
            ds.push_back(arr[i]);
            findCombination(i+1, target - arr[i], arr, ans, ds); 
            ds.pop_back(); 
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans; 
        vector<int> ds; 
        findCombination(0, target, candidates, ans, ds); 
        return ans; 
    }
};
```

#### [Palindrome Partitining](https://leetcode.com/problems/palindrome-partitioning/)
#### [Video Solution](https://www.youtube.com/watch?v=WBgsABoClE0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=51)

```cpp

class Solution {
private:
    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--]){
                return false;
            }
        }
        
        return true;
    }
    
void func(int index, string s, vector<string> &path, 
              vector<vector<string> > &res) {
        
         if(index == s.size()) {
            res.push_back(path);
            return;
            }
        for(int i = index; i < s.size(); i++) {
            if (isPalindrome(s,index, i)){
                path.push_back(s.substr(index, i - index + 1));
                func(i+1, s, path, res);
                path.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> res;
        vector<string> path;
        
        func(0, s, path, res);
        return res;
    }
};

```

#### [k-th permutation sequence](https://leetcode.com/problems/permutation-sequence/)
#### [Video Solution](https://www.youtube.com/watch?v=wT7gcXLYoao&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=55)


```cpp

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        
        // finding factorial only upto n-1 not n
        // do remember this
        for(int i = 1; i < n; i++){
            fact = fact * i;
            numbers.push_back(i);
        }
        
        
        numbers.push_back(n);
        
        string ans = "";
        
        k = k - 1;
        while (true) {
            ans = ans + to_string(numbers[k/fact]);
            numbers.erase(numbers.begin() + k/fact);
            
            if(numbers.size() == 0){
                break;
            }
            
            k = k%fact;
            fact = fact / numbers.size();
        }
        
        return ans;
    }
};

```

#### [Print all permutations of array or string](https://leetcode.com/problems/permutations/)
#### [Video Solution](https://www.youtube.com/watch?v=f2ic2Rsc9pU&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=53)

```cpp

class Solution {
public:
    
    void recur(int index, vector<int>& nums, vector<vector<int>>& answer) {
        
        if (index == nums.size()) {
            answer.push_back(nums);
            return;
        }
        
        for(int i = index; i < nums.size(); i++) {
            
            swap(nums[index], nums[i]);
            recur(index + 1, nums, answer);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        int index = 0;
        recur(index, nums, answer);
        
        return answer;
    }
};

```

#### [n queens problem](https://leetcode.com/problems/n-queens/)
#### [Video Soluton](https://www.youtube.com/watch?v=i05Ju7AftcM&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=57)


```cpp
class Solution {
public:
    std::vector<std::vector<std::string> > solveNQueens(int n) {
        std::vector<std::vector<std::string> > res;
        std::vector<std::string> nQueens(n, std::string(n, '.'));
        solveNQueens(res, nQueens, 0, n);
        return res;
    }
private:
    void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, int row, int &n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (isValid(nQueens, row, col, n)) {
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
    }
    bool isValid(std::vector<std::string> &nQueens, int row, int col, int &n) {
        //check if the column had a queen before.
        for (int i = 0; i != row; ++i)
            if (nQueens[i][col] == 'Q')
                return false;
        //check if the 45Â° diagonal had a queen before.
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (nQueens[i][j] == 'Q')
                return false;
        //check if the 135Â° diagonal had a queen before.
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (nQueens[i][j] == 'Q')
                return false;
        return true;
    }
};

```

#### [Sudoku Solver](https://leetcode.com/problems/sudoku-solver/)
#### [Video Solution](https://www.youtube.com/watch?v=FWAIf_EVUKE&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=58)

```cpp
class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    // row check
    for(int i = 0; i < 9; i++) 
		if(board[i][col] == c) 
			return false;
	// col check
    for(int i = 0; i < 9; i++) 
		if(board[row][i] == c) 
			return false;
    // box check
    int x0 = (row/3) * 3, y0 = (col/3) * 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[x0 + i][y0 + j] == c) return false;
        }
    }
    return true;
}
    
    bool solve(vector<vector<char>>& board, int row, int col){
        
        if (row == 9) return true;
        if (col == 9) return solve(board, row + 1, 0);
        
        if(board[row][col] != '.') return solve(board, row, col + 1);
        
        for(char c = '1'; c <= '9'; c++){
            
            if (isValid(board, row, col, c)){
                board[row][col] = c;
                
                if (solve(board, row, col + 1)) {
                    return true;
                }
                
                board[row][col] = '.';
            }        
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board, 0, 0);
    }
};

```

#### [M Coloring Problem](https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#)
#### [Video Solution](https://www.youtube.com/watch?v=wuVwUK25Rfc&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=60)


```cpp
bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
    for(int k = 0;k<n;k++) {
        if(k != node && graph[k][node] == 1 && color[k] == col) {
            return false; 
        }
    }
    return true; 
}
bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
    if(node == N) {
        return true; 
    }
    
    for(int i = 1;i<=m;i++) {
        if(isSafe(node, color, graph, N, i)) {
            color[node] = i;
            if(solve(node+1, color, m, N, graph)) return true; 
            color[node] = 0; 
        }
        
    }
    return false; 
}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int N)
{
    int color[N] = {0};
    if(solve(0,color,m,N,graph)) return true; 
    return false; 
}
```

#### [Rat in a Maze](https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1)
#### [Video Solution](https://youtu.be/bLGZhJlt4y0?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma)

```cpp
void solve(int i, int j, vector<vector<int>>& a, int n, vector<string>& ans, string move, vector<vector<bool>>& vis){
    
    if(i == n-1 && j == n - 1){
        ans.push_back(move);
        return;
    }
    
    // downward
    if (i+1 < n && !vis[i+1][j] && a[i+1][j] == 1){
        vis[i][j] = true;
        solve(i+1, j, a, n, ans, move + 'D', vis);
        vis[i][j] = false;
    }
    
    // left
    if(j-1 >= 0 && !vis[i][j-1] && a[i][j-1] == 1){
        vis[i][j] = true;
        solve(i, j - 1, a, n, ans, move + 'L', vis);
        vis[i][j] = false;
    }
    
    // right
    if( j+1 < n && !vis[i][j+1] && a[i][j+1] == 1 ){
        vis[i][j] = true;
        solve(i, j+1, a, n, ans, move + 'R', vis);
        vis[i][j] = false;
    }
    
    // upward
    if(i-1 >= 0 && !vis[i-1][j] && a[i-1][j] == 1){
        vis[i][j] = true;
        solve(i-1, j, a, n, ans, move + 'U', vis);
        vis[i][j] = false;
    }
}

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        if (m[0][0] == 1) solve(0, 0, m, n, ans, "", vis);
        
        return ans;
    }
};
```

#### [Word break problem usign backtracking](https://www.geeksforgeeks.org/word-break-problem-using-backtracking/)
#### [Geeks for geeks solution](https://www.geeksforgeeks.org/word-break-problem-using-backtracking/)

```cpp

// A recursive program to print all possible
// partitions of a given string into dictionary
// words
#include <iostream>
using namespace std;

/* A utility function to check whether a word
is present in dictionary or not. An array of
strings is used for dictionary. Using array
of strings for dictionary is definitely not
a good idea. We have used for simplicity of
the program*/
int dictionaryContains(string &word)
{
	string dictionary[] = {"mobile","samsung","sam","sung",
							"man","mango", "icecream","and",
							"go","i","love","ice","cream"};
	int n = sizeof(dictionary)/sizeof(dictionary[0]);
	for (int i = 0; i < n; i++)
		if (dictionary[i].compare(word) == 0)
			return true;
	return false;
}

// Prototype of wordBreakUtil
void wordBreakUtil(string str, int size, string result);

// Prints all possible word breaks of given string
void wordBreak(string str)
{
	// Last argument is prefix
	wordBreakUtil(str, str.size(), "");
}

// Result store the current prefix with spaces
// between words
void wordBreakUtil(string str, int n, string result)
{
	//Process all prefixes one by one
	for (int i=1; i<=n; i++)
	{
		// Extract substring from 0 to i in prefix
		string prefix = str.substr(0, i);

		// If dictionary contains this prefix, then
		// we check for remaining string. Otherwise
		// we ignore this prefix (there is no else for
		// this if) and try next
		if (dictionaryContains(prefix))
		{
			// If no more elements are there, print it
			if (i == n)
			{
				// Add this element to previous prefix
				result += prefix;
				cout << result << endl;
				return;
			}
			wordBreakUtil(str.substr(i, n-i), n-i,
								result + prefix + " ");
		}
	}	
}

//Driver Code
int main()
{

	// Function call
	cout << "First Test:\n";
	wordBreak("iloveicecreamandmango");

	cout << "\nSecond Test:\n";
	wordBreak("ilovesamsungmobile");
	return 0;
}

```

#### [Word break using DP](https://www.geeksforgeeks.org/word-break-problem-dp-32/)
#### above link has both question and solution of geeks for geeks

## Do read this again because you have not learnt this (Leet code 139)

```cpp
// A Dynamic Programming based program to test whether a given string can
// be segmented into space separated words in dictionary
#include <iostream>
#include <string.h>
using namespace std;

/* A utility function to check whether a word is present in dictionary or not.
An array of strings is used for dictionary. Using array of strings for
dictionary is definitely not a good idea. We have used for simplicity of
the program*/
int dictionaryContains(string word)
{
	string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
						"icecream","and","go","i","like","ice","cream"};
	int size = sizeof(dictionary)/sizeof(dictionary[0]);
	for (int i = 0; i < size; i++)
		if (dictionary[i].compare(word) == 0)
		return true;
	return false;
}

// Returns true if string can be segmented into space separated
// words, otherwise returns false
bool wordBreak(string str)
{
	int size = str.size();
	if (size == 0) return true;

	// Create the DP table to store results of subroblems. The value wb[i]
	// will be true if str[0..i-1] can be segmented into dictionary words,
	// otherwise false.
	bool wb[size+1];
	memset(wb, 0, sizeof(wb)); // Initialize all values as false.

	for (int i=1; i<=size; i++)
	{
		// if wb[i] is false, then check if current prefix can make it true.
		// Current prefix is "str.substr(0, i)"
		if (wb[i] == false && dictionaryContains( str.substr(0, i) ))
			wb[i] = true;

		// wb[i] is true, then check for all substrings starting from
		// (i+1)th character and store their results.
		if (wb[i] == true)
		{
			// If we reached the last prefix
			if (i == size)
				return true;

			for (int j = i+1; j <= size; j++)
			{
				// Update wb[j] if it is false and can be updated
				// Note the parameter passed to dictionaryContains() is
				// substring starting from index 'i' and length 'j-i'
				if (wb[j] == false && dictionaryContains( str.substr(i, j-i) ))
					wb[j] = true;

				// If we reached the last character
				if (j == size && wb[j] == true)
					return true;
			}
		}
	}

	/* Uncomment these lines to print DP table "wb[]"
	for (int i = 1; i <= size; i++)
		cout << " " << wb[i]; */

	// If we have tried all prefixes and none of them worked
	return false;
}

// Driver program to test above functions
int main()
{
	wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
	wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
	wordBreak("")? cout <<"Yes\n": cout << "No\n";
	wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
	wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n";
	wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n";
	return 0;
}
```


#### [Word Break](https://leetcode.com/problems/word-break/)

```cpp

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size() == 0) return false;
        
        vector<bool> dp(s.size() + 1, false);
        
        dp[0] = true;
        
        set<string> dict;
        for(auto words: wordDict) dict.insert(words);
        
        for(int i = 1; i <= s.size(); i++) {
            for(int j= i -1; j >= 0; j--) {
                
                if(dp[j]){
                    string word = s.substr(j, i-j);
                    
                    if(dict.find(word) != dict.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
};

```


#### [Square root of x using binary search](https://leetcode.com/problems/sqrtx/)

```cpp

class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = x, mid;
        
        if (x < 2) return x; // to avoid mid == 0
        
        while(low < high) {
            mid = (low + high) / 2;
            
            if (x >= (long)mid * mid) low = mid + 1;
            else high = mid;
            
        }
        
        return high -1;
    }
};

```

#### In general nth root of x using binary search is..

```cpp

#include<bits/stdc++.h>
using namespace std;

double multiply(double number, int n) {
    double ans  = 1.0;

    for(int i = 1; i <= n; i++) {
        ans = ans * number;
    }

    return ans;
}

double getNthroot(int n, int m) {
    double low = 1;
    double high = m;
    double eps = 1e-6;

    while( (high-low) > eps) {
        double mid = (low + high) / 2.0;
        if (multiply(mid, n) < m) {
            low = m;
        }

        else{
            high = m;
        }
    }

    // below lines are just to check
    cout << low << " " << high << endl;

    cout << pow(m, (double)(1.0/(double)n));

}

int main() {
    int n, m;
    cin >> n >> m;

    getNthroot(n, m);
    return 0;
}

```

#### [Matrix Median](https://www.interviewbit.com/problems/matrix-median/)
#### [Video Solution](https://www.youtube.com/watch?v=63fPPOdIr2c&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=63)

```cpp
int countSmallerThanMid(vector<int> &row, int mid) {
    int l = 0, h = row.size() - 1; 
    while(l <= h) {
        int md = (l + h) >> 1; 
        if(row[md] <= mid) {
            l = md + 1;
        }
        else {
            h = md - 1;
        }
    }
    return l; 
}
int Solution::findMedian(vector<vector<int> > &A) {
    int low = INT_MIN;
    int high = INT_MAX; 
    int n = A.size();
    int m = A[0].size(); 
    while(low <= high) {
        int mid = (low + high) >> 1; 
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            cnt += countSmallerThanMid(A[i], mid); 
        }
        
        if(cnt <= (n * m) / 2) low = mid + 1; 
        else high = mid - 1; 
    }
    return low; 
}
```


#### [Single element in a sorted array](https://leetcode.com/problems/single-element-in-a-sorted-array/)
#### [Video Solution](https://www.youtube.com/watch?v=PzszoiY5XMQ&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=65)

```cpp

int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 2; 
        while(low <= high) {
            int mid = (low + high) >> 1; 


            // xor with 1 if number is even will give immediate next number (odd number)
            // if the number is odd will result in immediate previous number (even number)

            if(nums[mid] == nums[mid^1]) {
                low = mid + 1; 
            } 
            else {
                high = mid - 1; 
            }
        }
        return nums[low]; 
    }

```


#### [Search in rotated sorted array](https://leetcode.com/problems/search-in-rotated-sorted-array/)

#### [Video Solution](https://youtu.be/r3pMQ8-Ad5s?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma)

```cpp

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low = 0, high = nums.size() - 1;
        
        while(low <= high) {
            
            int mid = (low + high) >> 1;
            
            if(nums[mid] == target) return mid;
            
            if (nums[low] <= nums[mid]){
                if (target >= nums[low] && target <= nums[mid]){
                    high = mid - 1;
                }
                
                else{
                    low = mid + 1;
                }
            }
            
            else{
                if(target >= nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return -1;       
        
    }
};
```



#### Erricthos method to search in rotated sorted array

```cpp

class Solution {
public:
int search (vector<int>& nums, int target) {
    
    int n = nums.size();

    if (n == 0){
        return -1;
    }

    int low = 0, high = n -1;
    int first = nums[0];

    while(low <= high) {
        int mid = low + (high - low) / 2;
        int value = nums[mid];

        if (value == target){
            return mid;
        }
        // else we need decide whether we have to go right or left of the array
        bool i_am_big = value >= first;
        bool target_big = target >= first;

        // if both are same
        // if both are bigger or smaller than first
        // then they are in the same part
        // and we need to compare values to check
        // if we need to move left or right
        if ( i_am_big == target_big ) {
            // if current value is smaller than target
            // the we need to search right
            if ( value < target ) {
                low = mid + 1;
            }
            // other wise we need search in right part
            else {
                high = mid - 1;
            }
        }
        // if both are on opposite part
        else {
            // if value is big
            if (i_am_big) {
                // which means target is small
                // we need to move right
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }

    return -1;
}
};
```

#### [Median of 2 sorted arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)
#### [Video solution](https://youtu.be/NTop3VTjmxk?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma)

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // calling the smaller one as nums1 
        if (nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int low = 0, high = n1;
        
        while(low <= high) {
            
            int cut1 = (low + high) >> 1;
            int cut2 = (n1 + n2 + 1)/ 2 - cut1;
            
            
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 -1];
            
            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];
            
            if(left1 <= right2 && left2 <= right1){
                
                if( (n1+n2)%2 == 0){                  
                    
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
                
                else{
                    return max(left1, left2);
                }
            }
            
            else if (left1 > right2){
                high = cut1 - 1;
            }
            
            else{
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
};

```

#### [kth element in 2 sorted arrays](https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1)
#### [Video Solution](https://youtu.be/nv7F4PiLUzo?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma)

```cpp

class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if (n > m)
            return kthElement(arr2, arr1, m, n, k);
            
        int low = max(0, k -m), high = min(k, n);
        
        while( low <= high ){
            int cut1 = (low + high) >> 1;
            int cut2 = k - cut1;
            
            int l1 = cut1 == 0 ? INT_MIN: arr1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN: arr2[cut2 - 1];
            
            int r1 = cut1 == n ? INT_MAX: arr1[cut1];
            int r2 = cut2 == m ? INT_MAX: arr2[cut2];
            
            if(l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            }
            
            else if (l1 > r2) {
                high = cut1 - 1;
            }
            
            else{
                low = cut1 + 1;
            }
        }
        // as always k is less than or eqaul to sum of two array sizes
        // we don't need to return any thing at end else we may return -1
        return -1;
    }
};
```

#### [Allocate minimum number of pages](https://www.interviewbit.com/problems/allocate-books/)
#### [Video Solution](https://www.youtube.com/watch?v=gYmWHvRHu-s&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=69)


```cpp

int isPossible(vector<int> &A, int pages, int students) {
    int cnt = 0;
    int sumAllocated = 0; 
    for(int i = 0;i<A.size();i++) {
        if(sumAllocated + A[i] > pages) {
            cnt++; 
            sumAllocated = A[i];
            if(sumAllocated > pages) return false; 
        }
        else {
            sumAllocated += A[i];
        }
    }
    if(cnt < students) return true; 
    return false; 
}
int Solution::books(vector<int> &A, int B) {
    if(B > A.size()) return -1; 
    int low = A[0]; 
    int high = 0;
    for(int i = 0;i<A.size();i++) {
        high = high + A[i]; 
        low = min(low, A[i]); 
    }
    int res = -1; 
    while(low <= high) {
        int mid = (low + high) >> 1; 
        //cout << low << " " << high << " " << mid << endl; 
        if(isPossible(A, mid, B)) {
            res = mid; 
            high = mid - 1; 
        }
        else {
            low = mid + 1; 
        }
    }
    // return res -> this is also correct
    return low; 
}
```

#### [Aggressive cows](https://www.spoj.com/problems/AGGRCOW/)
#### This is the question of maximising the minimum
#### Remember if there is something like maximize the mimimum or minimize the maximum go for binary search
#### [Video Solution](https://youtu.be/wSOfYesTBRk?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma)


```cpp

#include<bits/stdc++.h>
using namespace std;

bool isPossible(int a[], int n, int cows, int minDist){

    int cntCows = 1;
    int lasPlacedCow = a[0];

    for(int i = 1; i < n; i++) {
        if (a[i] - lastPlacedCow >= minDist){
            cntCows++;
            lastPlacedCow = a[i];
        }
    }

    if(cntCows >= cows) return true;
    return false;

}

int main() {

    int t;
    cin >> t;

    while(t--) {

        int n, cows;
        cin >> n >> cows;

        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a+n);

        int low = 1, high = a[n-1] - a[0];

        while(low <= high) {
            int mid = (low + high) >> 1;

            if (isPossible(a, n, cows, mid)) {
                low = mid + 1;
            }

            else{
                high = mid - 1;
            }
        }

        cout << high << endl;
    }

    return 0;
}

```

#### [Check if a number is power of 2 or not is order of 1 time](https://leetcode.com/problems/power-of-two/)

```cpp

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if (n<=0) return false;
        
        return n && !(n & (n-1));
        
    }
};

```

#### [Count total set bits](https://leetcode.com/problems/counting-bits/)

```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> ans;
        
        for(int i = 0; i <= n; i++) ans.push_back(__builtin_popcount(i));
        
        return ans;
    }
};
```


#### [Divide integers without using division (/) operator](https://leetcode.com/problems/divide-two-integers/)

#### [Video Solution](https://youtu.be/htX69j1jf5U)


```cpp

    int divide(int A, int B) {
        if (A == INT_MIN && B == -1) return INT_MAX;
        int a = abs(A), b = abs(B), res = 0, x = 0;
        while (a - b >= 0) {
            for (x = 0; a - (b << x << 1) >= 0; x++);
            res += 1 << x;
            a -= b << x;
        }
        return (A > 0) == (B > 0) ? res : -res;
    }

```

#### other method is

```cpp

    int divide(int A, int B) {
        if (A == INT_MIN && B == -1) return INT_MAX;
        int a = abs(A), b = abs(B), res = 0;
        for (int x = 31; x >= 0; x--)
            if ((signed)((unsigned)a >> x) - b >= 0)
                res += 1 << x, a -= b << x;
        return (A > 0) == (B > 0) ? res : -res;
    }


```
## Very Very important
#### [For the given string find all the possible subsequence using powerset](https://practice.geeksforgeeks.org/problems/power-set4302/1#)

#### [Video Solution](https://www.youtube.com/watch?v=b7AYbpM5YrE&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=68)

```cpp

vector<string> AllPossibleStrings(string s){
		    int n = s.size(); 
		    vector<string> ans; 
		    for(int num = 0; num < (1 << n); num++) {
		        string sub = ""; 
		        for(int i = 0;i<n;i++) {
		            if(num & (1<<i)) {
		                sub += s[i];
		            }
		        }
		        if(sub.size() > 0)
		            ans.push_back(sub);
		    }
		    sort(ans.begin(), ans.end()); 
		    return ans; 
		}
```

#### [Calculate square of a number without using *, / or pow](https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/)

```cpp
// Square of a number using bitwise operators
#include <bits/stdc++.h>
using namespace std;

int square(int n)
{
	// Base case
	if (n == 0)
		return 0;

	// Handle negative number
	if (n < 0)
		n = -n;

	// Get floor(n/2) using right shift
	int x = n >> 1;

	// If n is odd
	if (n & 1)
		return ((square(x) << 2) + (x << 2) + 1);
	else // If n is even
		return (square(x) << 2);
}

// Driver Code
int main()
{
	// Function calls
	for (int n = 1; n <= 5; n++)
		cout << "n = " << n << ", n^2 = " << square(n)
			<< endl;
	return 0;
}

```

#### Implementation of stack using arrays

```cpp

int array[5];
int top = -1;

void push(x) {
    array[++top] = x;
}

void pop(){
    top--;
}

int top(){
    return array[top];
}

int size(){
    return top+1;
}

bool isEmpty(){

    return top == -1;
}

```

#### Implement Queue using arrays

```cpp

int array[max_size];

void push(x){
    if (count == max_size) return;
    array[rear % n] = x;
    rear++;
    count++;
}


void pop() {
    if (count == 0) return;

    array[front % n] = -1;
    front++;
    count--;
}

int top(){
    
    if (count == 0) return -1;
    return array[front%n];
}

int size() {
    return count;
}

```

#### [Implement stack using single queue](https://leetcode.com/problems/implement-stack-using-queues/)
#### [Video Solution](https://www.youtube.com/watch?v=jDZQKzEtbYQ&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=75)

```cpp

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        
        for(int i = 0; i < q.size() -1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
 ```

 #### [Implement queue using stacks](https://leetcode.com/problems/implement-queue-using-stacks/)
 #### [Video Solution](https://www.youtube.com/watch?v=3Et9MrMc02A&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=75)

```cpp
class MyQueue {
public:
stack<int> input, output;
MyQueue() {
    
}

void push(int x) {
    input.push(x);
    
}

int pop() {
    if(!output.empty()) {
        int x = output.top();
        output.pop();
        return x;
    }
    
    while(!input.empty()){
        output.push(input.top());
        input.pop();
    }
    
    int x = output.top();
    output.pop();
    return x;
}

int peek() {
    if(!output.empty()){
        return output.top();
    }
    
    while(!input.empty()){
        output.push(input.top());
        input.pop();
    }
    
    return output.top();
}

bool empty() {
    
    if(input.empty() && output.empty()) return true;
    return false;
}
};

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue* obj = new MyQueue();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->peek();
* bool param_4 = obj->empty();
*/
``` 

#### [Valid parenthesis](https://leetcode.com/problems/valid-parentheses/)


```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (char& c : s) {
            switch (c) {
                case '(': 
                case '{': 
                case '[': paren.push(c); break;
                case ')': if (paren.empty() || paren.top()!='(') return false; else paren.pop(); break;
                case '}': if (paren.empty() || paren.top()!='{') return false; else paren.pop(); break;
                case ']': if (paren.empty() || paren.top()!='[') return false; else paren.pop(); break;
                default: ; // pass
            }
        }
        return paren.empty() ;
    }
};
```
#### [next greater element](https://leetcode.com/problems/next-greater-element-i/)
#### [video solution](https://www.youtube.com/watch?v=Du881K7Jtk8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=76)

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int n : nums) {
            while (s.size() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> ans;
        for (int n : findNums) ans.push_back(m.count(n) ? m[n] : -1);
        return ans;
    }
};
```

#### [Sort a stack](https://www.youtube.com/watch?v=MOGBRkkOhkY)
#### above link has the solution not the link to the question

```cpp
// C++ program to sort a stack using recursion
#include <iostream>
using namespace std;

// Stack is represented using linked list
struct stack {
	int data;
	struct stack* next;
};

// Utility function to initialize stack
void initStack(struct stack** s) { *s = NULL; }

// Utility function to check if stack is empty
int isEmpty(struct stack* s)
{
	if (s == NULL)
		return 1;
	return 0;
}

// Utility function to push an item to stack
void push(struct stack** s, int x)
{
	struct stack* p = (struct stack*)malloc(sizeof(*p));

	if (p == NULL) {
		fprintf(stderr, "Memory allocation failed.\n");
		return;
	}

	p->data = x;
	p->next = *s;
	*s = p;
}

// Utility function to remove an item from stack
int pop(struct stack** s)
{
	int x;
	struct stack* temp;

	x = (*s)->data;
	temp = *s;
	(*s) = (*s)->next;
	free(temp);

	return x;
}

// Function to find top item
int top(struct stack* s) { return (s->data); }

// Recursive function to insert an item x in sorted way
void sortedInsert(struct stack** s, int x)
{
	// Base case: Either stack is empty or newly inserted
	// item is greater than top (more than all existing)
	if (isEmpty(*s) or x > top(*s)) {
		push(s, x);
		return;
	}

	// If top is greater, remove the top item and recur
	int temp = pop(s);
	sortedInsert(s, x);

	// Put back the top item removed earlier
	push(s, temp);
}

// Function to sort stack
void sortStack(struct stack** s)
{
	// If stack is not empty
	if (!isEmpty(*s)) {
		// Remove the top item
		int x = pop(s);

		// Sort remaining stack
		sortStack(s);

		// Push the top item back in sorted stack
		sortedInsert(s, x);
	}
}

// Utility function to print contents of stack
void printStack(struct stack* s)
{
	while (s) {
		cout << s->data << " ";
		s = s->next;
	}
	cout << "\n";
}

// Driver code
int main(void)
{
	struct stack* top;

	initStack(&top);
	push(&top, 30);
	push(&top, -5);
	push(&top, 18);
	push(&top, 14);
	push(&top, -3);

	cout << "Stack elements before sorting:\n";
	printStack(top);

	sortStack(&top);
	cout << "\n";

	cout << "Stack elements after sorting:\n";
	printStack(top);

	return 0;
}

// This code is contributed by SHUBHAMSINGH10
```

#### below code is more understandable in python

```python

# Python program to sort a stack using recursion

# Recursive method to insert element in sorted way


def sortedInsert(s, element):

	# Base case: Either stack is empty or newly inserted
	# item is greater than top (more than all existing)
	if len(s) == 0 or element > s[-1]:
		s.append(element)
		return
	else:

		# Remove the top item and recur
		temp = s.pop()
		sortedInsert(s, element)

		# Put back the top item removed earlier
		s.append(temp)

# Method to sort stack


def sortStack(s):

	# If stack is not empty
	if len(s) != 0:

		# Remove the top item
		temp = s.pop()

		# Sort remaining stack
		sortStack(s)

		# Push the top item back in sorted stack
		sortedInsert(s, temp)

# Printing contents of stack


def printStack(s):
	for i in s[::-1]:
		print(i, end=" ")
	print()


# Driver Code
if __name__ == '__main__':
	s = []
	s.append(30)
	s.append(-5)
	s.append(18)
	s.append(14)
	s.append(-3)

	print("Stack elements before sorting: ")
	printStack(s)

	sortStack(s)

	print("\nStack elements after sorting: ")
	printStack(s)

# This code is contributed by Muskan Kalra.
```


#### [Find previous smaller element](https://www.interviewbit.com/problems/nearest-smaller-element/)

### if you want next smaller element run loop from 0
### if there is no case like cirucalar array then you can only run loop upto n instead of 2n

```cpp

vector<int> Solution::prevSmaller(vector<int> &A) {

    int n = A.size();
    vector<int> ans(n);
    stack<pair<int,int>> st;

    for(int i = 2*n-1; i >= 0; i--) {
        int next = A[i%n];

        if (st.empty()){
            st.push({next, i%n});
            continue;
        }

        while(!st.empty() && st.top().first > next) {
            ans[st.top().second ] = next;
            st.pop();
        }

        st.push({next, i%n});
    }

    while( !st.empty()){
        ans[st.top().second] = -1;
        st.pop();
    }

    return ans;
}
```

#### [LRU Cache](https://leetcode.com/problems/lru-cache/)
#### [Video Solution](https://youtu.be/xDEuM5qa0zg?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma)

#### Errichto version

```cpp

class LRUCache {
    
private:
    unordered_map<int,int> value; // keeping existing elements
    queue<int> accessed;
    unordered_map<int,int> cnt_in_queue;
    int capacity;
    
    void add_to_q(int key) {
        accessed.push(key);
        cnt_in_queue[key]++;
    }
    
public:
    LRUCache(int given_capacity) {
        capacity = given_capacity;
    }
    
    int get(int key) {
        auto it = value.find(key);
        
        if(it == value.end()) {
            return -1;
        }
        
        add_to_q(key);
        
        return it->second; // return value[key] but this is bit slower
    }
    
    void put(int key, int v) {
        
        if((int) value.size() < capacity) {
            value[key] = v;
            add_to_q(key);
            return;
        }
        
        auto it = value.find(key);
        if (it != value.end()) {
            it->second = v;
            add_to_q(key);
            return;
        }
        
        while(true) {
            int candidate = accessed.front();
            accessed.pop();
            
            if(--cnt_in_queue[candidate] == 0) {
                value.erase(candidate);
                break;
            }
        }
        value[key] = v;
        add_to_q(key);
    }
};

```


#### Striver Version

```cpp

class LRUCache {
public:
    
    class node{
        public:
            int key;
            int val;
            node* next;
            node* prev;
            node(int _key, int _val) {
                key = _key;
                val = _val;
            }
    };
    
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    
    int cap;
    unordered_map<int, node*> m;
    
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node* newnode){
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key_){
        
        if(m.find(key_) != m.end()) {
            
            node* resnode = m[key_];
            int res = resnode->val;
            
            m.erase(key_);
            
            deletenode(resnode);
            addnode(resnode);
            
            m[key_] = head->next;
            
            return res;
        
        }
        
        return -1;
    }
    
//     int get(int key) {
        
//     }
    
    void put(int key_, int value) {
        
        // just in case if it is previosly existed we have to delete it
        // both from map and double linked list
        if(m.find(key_) != m.end()) {
            node* existnode =   m[key_];
            m.erase(key_);
            deletenode(existnode);
        }
        
        if(m.size() == cap) {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        addnode(new node(key_, value));
        m[key_] = head->next;
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 ```

#### [ (LFU) Least Frequently Used Cache](https://leetcode.com/problems/lfu-cache/)
#### [Video Solution](https://www.youtube.com/watch?v=0PSB9y8ehbk)

#### [Explanation for below is code is in the comment section](https://leetcode.com/problems/lfu-cache/discuss/94516/Concise-C%2B%2B-O(1)-solution-using-3-hash-maps-with-explanation)


```cpp

class LFUCache {
public:
    LFUCache(int capacity) {
        this -> capacity = capacity;
        size = 0;
    }
    
    int get(int key) {
        if (values.find(key) == values.end()) {
            return -1;
        }
        update(key);
        return values[key].first;
    }
    
    void put(int key, int value) {
        if (!capacity) {
            return;
        }
        if (values.find(key) != values.end()) {
            values[key].first = value;
            update(key);
        } else {
            if (size == capacity) {
                int evict = keys[lfu].front();
                keys[lfu].pop_front();
                values.erase(evict);
                iters.erase(evict);
            } else {
                size++;
            }
            values[key] = {value, 1};
            keys[1].push_back(key);
            iters[key] = --keys[1].end();
            lfu = 1;
        }
    }
private:
    int capacity, size, lfu = 0;
    unordered_map<int, list<int>> keys;
    unordered_map<int, pair<int, int>> values;
    unordered_map<int, list<int>::iterator> iters;
    
    void update(int key) {
        int freq = values[key].second;
        auto iter = iters[key];
        values[key].second++;
        keys[freq].erase(iter);
        keys[freq + 1].push_back(key);
        iters[key] = --keys[freq + 1].end();
        if (keys[lfu].empty()) {
            lfu++;
        }
    }
};

```

#### [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)
#### [Two pass solution](https://youtu.be/X0X6G-eWgQ8?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma)


#### Two pass code

```cpp

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        
        int leftsmall[n], rightsmall[n];
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            
            if(st.empty()) leftsmall[i] = 0;
            else leftsmall[i] = st.top() + 1;
            
            st.push(i);
        }
        
        //clearing the stack to reuse
        while(!st.empty()) st.pop();
        
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >=  heights[i]) {
                st.pop();
            }
            
            if(st.empty()) rightsmall[i] = n-1;
            else rightsmall[i] = st.top() - 1;
            
            st.push(i);
        }
        
        int maxA = 0;
        
        for(int i = 0; i < n; i++) {
            maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
        }
        
        return maxA;
        
    }
};


```

#### [One pass solution](https://www.youtube.com/watch?v=jC_cWLy7jSI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=83)

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxA = 0;
        
        int n = heights.size();
        
        for(int i = 0; i <= n; i++) {
            
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){
                int height = heights[st.top()];
                st.pop();
                
                int width;
                if (st.empty()) width = i;
                else width = i - st.top() - 1;
                maxA = max(maxA, width * height);
            }
            
            st.push(i);
        }
        return maxA;
    }
};

```


#### [Sliding Windows Maximum](https://leetcode.com/problems/sliding-window-maximum/)
#### [Video Solution](https://youtu.be/CZQGRp93K4k?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma)

```cpp

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        vector<int> ds;
        
        for(int i = 0; i < nums.size(); i++){
            // removing out of bounds
            if(!dq.empty() && dq.front() == i-k ) dq.pop_front();
            
            
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            
            dq.push_back(i);
            
            if(i >= k-1) ds.push_back(nums[dq.front()]);
        }
        return ds;
    }
};

```
#### [Implement Min stack](https://leetcode.com/problems/min-stack/)
#### [Video Solution](https://youtu.be/V09NfaGf2ao)

#### Using 2N space complexity that is stack of pairs

```cpp
class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val, val});
        }
        else{
            st.push({val, min(val, st.top().second)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
       return st.top().first; 
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
 ```

 #### [ORder of N approach in space](https://www.youtube.com/watch?v=V09NfaGf2ao)
 #### if ele < min then ele = 2* ele - min (this is the main point to remeber)


```cpp
class MinStack {
    stack<long long>st;
    long long mini;
public:
    MinStack() {
        while(st.empty() == false) st.pop();
        mini = INT_MAX;
    }
    
    void push(int value) {
        long long val = value;
        if (st.empty()){
            mini = val;
            st.push(val);
        }
        else{
            if(val < mini){
                st.push(2 * val * 1LL - mini);
                mini =val;
            }
            
            else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        
        long long el = st.top();
        st.pop();
        
        if(el < mini){
            mini = 2 * mini - el;
        }
        
    }
    
    int top() {
        if(st.empty()) return -1;
        
        long long el = st.top();
        if(el < mini) return mini;
        return el;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 ```

#### [Rotten Oranges](https://leetcode.com/problems/rotting-oranges/)
#### [Video solution](https://youtu.be/pUAPcVlHLKA)


```cpp

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        vector<int> dir = {-1,0,1,0,-1};
        
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>> q;
        
        int fresh = 0;
        
        // pushing all the rotten oranges
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i,j});
                }
                
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        int ans = -1;
        
        while(!q.empty()){
            
            int sz = q.size();
            
            while(sz--) {
                
                pair<int,int> p = q.front();
                q.pop();
                
                for(int i = 0; i < 4; i++) {
                    int r = p.first + dir[i];
                    int c = p.second + dir[i+1];
                    
                    if (r >= 0&& r < m && c >= 0 && c < n && grid[r][c] == 1) {
                        grid[r][c] = 2;
                        q.push({r,c});
                        fresh--;
                    }
                }
            }
            ans++;
        }
        
        if (fresh > 0) return -1;
        
        if (ans == -1) return 0;
        
        return ans;
    }
};
```

#### [Online stock span](https://leetcode.com/problems/online-stock-span/)
#### [Blog Solution](https://leetcode.com/problems/online-stock-span/discuss/636856/Single-stack-explanation-with-Diagram)
#### this is similar to next greater element in the left of array just a slight variation of it


```cpp

class StockSpanner {
public:
    stack<pair<int,int>> sk;
    StockSpanner() {    }
    
    int next(int price) {
	
        int ct = 1;
        while(sk.size() and sk.top().first <= price)    // as shown in during Dry run on sample input
				ct+=sk.top().second , sk.pop();            // we add count of poped element's count
				
        sk.push({price , ct});
        return ct;
    }
};

```

#### [Find maximum of minimum of all window sizes](https://www.geeksforgeeks.org/find-the-maximum-of-minimums-for-every-window-size-in-a-given-array/)
#### both the question and answer
#### this is similar to next smaller or greater which uses stack


```cpp
// An efficient C++ program to find
// maximum of all minimums of
// windows of different sizes
#include <iostream>
#include<stack>
using namespace std;

void printMaxOfMin(int arr[], int n)
{
// Used to find previous and next smaller
	stack<int> s;

	// Arrays to store previous and next smaller
	int left[n+1];
	int right[n+1];

	// Initialize elements of left[] and right[]
	for (int i=0; i<n; i++)
	{
		left[i] = -1;
		right[i] = n;
	}

	// Fill elements of left[] using logic discussed on
	// https://www.geeksforgeeks.org/next-greater-element/
	for (int i=0; i<n; i++)
	{
		while (!s.empty() && arr[s.top()] >= arr[i])
			s.pop();

		if (!s.empty())
			left[i] = s.top();

		s.push(i);
	}

	// Empty the stack as stack is
// going to be used for right[]
	while (!s.empty())
		s.pop();

	// Fill elements of right[] using same logic
	for (int i = n-1 ; i>=0 ; i-- )
	{
		while (!s.empty() && arr[s.top()] >= arr[i])
			s.pop();

		if(!s.empty())
			right[i] = s.top();

		s.push(i);
	}

	// Create and initialize answer array
	int ans[n+1];
	for (int i=0; i<=n; i++)
		ans[i] = 0;

	// Fill answer array by comparing minimums of all
	// lengths computed using left[] and right[]
	for (int i=0; i<n; i++)
	{
		// length of the interval
		int len = right[i] - left[i] - 1;

		// arr[i] is a possible answer for this length
		// 'len' interval, check if arr[i] is more than
		// max for 'len'
		ans[len] = max(ans[len], arr[i]);
	}

	// Some entries in ans[] may not be filled yet. Fill
	// them by taking values from right side of ans[]
	for (int i=n-1; i>=1; i--)
		ans[i] = max(ans[i], ans[i+1]);

	// Print the result
	for (int i=1; i<=n; i++)
		cout << ans[i] << " ";
}

// Driver program
int main()
{
	int arr[] = {10, 20, 30, 50, 10, 70, 30};
	int n = sizeof(arr)/sizeof(arr[0]);
	printMaxOfMin(arr, n);
	return 0;
}

```

#### [the celebrity problem](https://leetcode.com/problems/find-the-celebrity/)
#### well it is locked 
#### [find the problem and solution here in GFG](https://www.geeksforgeeks.org/the-celebrity-problem/)



## Above has no solutoin done you can find in the blog as it is not that much important i have not placed it here

#### [Reverse words in a string](https://leetcode.com/problems/reverse-words-in-a-string/)


```cpp
class Solution {
public:
    string reverseWords(string s) {
        vector<string> array;
        
        string str = "";
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == 32) {
                array.push_back(str);
                str = "";
            }
            else{
                str += s[i];
            }
        }
        
        array.push_back(str);
        
        string answer="";
        
        for(int i = array.size() - 1; i >= 1; i++) {
            answer += array[i];
            
            answer += " ";
        }        
        
        answer += array[0];
        
        return answer;
    }
};
```
### we can also approach above problem without taking extra space as reverse the whole string first then reverse word by word


#### [Longest palindromic substring](https://leetcode.com/problems/longest-palindromic-substring/)

```cpp

class Solution {
public:
    pair<int,int> getstring(string& s, int center1, int center2){
        
       
        
        int left = center1, right = center2;
        
        while(left >= 0 && right <= (int)s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        
        
        return {++left, --right};
        
    }
    
    string longestPalindrome(string s) {
        
        
        pair<int, int> answer (0,0);
        
        for(int i = 0; i < (int)s.length(); i++){
            pair<int,int> even = getstring(s, i, i+1);
            pair<int,int> odd = getstring(s, i , i);
            cout << "even" << even.first << even.second << " " << "odd" << odd.first << odd.second << " " << s[i] << endl;
            answer = (even.second - even.first > odd.second - odd.first) ? (answer.second- answer.first > even.second - even.first ? answer : even) : (answer.second - answer.first > odd.second - odd.first ? answer : odd);
        }
        
        cout << "final answer is " << answer.first << " " << answer.second;
        
        return s.substr(answer.first, answer.second - answer.first + 1);
        
    }
};
```

#### [Roman to Integer](https://leetcode.com/problems/roman-to-integer/)

```cpp

class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char,int> values = {
            {'M', 1000},
            {'D', 500},
            {'C', 100},
            {'L', 50},
            {'X', 10},
            {'V', 5},
            {'I', 1}
    };
        int answer = 0;
        int prev = 0;
        
        for(int i = (int)s.length() -1; i >=0; i--) {
        
            int curr = values[s[i]];
            
            if (curr >= prev){
                answer += curr;
            }
            
            else {
                answer -= curr;
            }
            
            prev = curr;
        }
        
        return answer;
        
    }
};

```

#### [String to integer atoi](https://leetcode.com/problems/string-to-integer-atoi/)
#### [Video solution](https://youtu.be/2I9XO8jwZCA)

```cpp
class Solution {
public:
    int myAtoi(string s) {
        
        int result = 0; // for storing the result
        int i = 0; // pointing to current character
        int sign = 1;
        
        // trimming all the spaces
        while(s[i] == ' ') i++;
        
        if(s[i] == '-') {
            sign = -1;
            i++;
        }
        
        while(s[i]) {
            if (!(s[i] - '0' >= 0 && s[i] -'0' <= 9)){
                return -1;
            }
            
            result = result * 10 + s[i] - '0';
            i++;
        }
        
        return result * sign;
    }
};
```

#### [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        
        int n = str.size();
        
        if (n == 0) return "";
        
        sort(str.begin(), str.end());
        
        string a = str[0];
        string b = str[n-1];
        
        string answer = "";
        
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == b[i]){
                answer += a[i];
            }
            
            else{
                return answer;
            }
        }
        
        return answer;
    }
};
```

####  [Rabin Carp Algorithm](https://leetcode.com/problems/repeated-string-match/discuss/416144/Rabin-Karp-algorithm-C%2B%2B-implementation)
#### [Video Explanation](https://youtu.be/BQ9E-2umSWc)

```cpp
/* Following program is a C++ implementation of Rabin Karp 
Algorithm given in the CLRS book */
#include <bits/stdc++.h> 
using namespace std; 

// d is the number of characters in the input alphabet 
#define d 256 

/* pat -> pattern 
	txt -> text 
	q -> A prime number 
*/
void search(char pat[], char txt[], int q) 
{ 
	int M = strlen(pat); 
	int N = strlen(txt); 
	int i, j; 
	int p = 0; // hash value for pattern 
	int t = 0; // hash value for txt 
	int h = 1; 

	// The value of h would be "pow(d, M-1)%q" 
	for (i = 0; i < M - 1; i++) 
		h = (h * d) % q; 

	// Calculate the hash value of pattern and first 
	// window of text 
	for (i = 0; i < M; i++) 
	{ 
		p = (d * p + pat[i]) % q; 
		t = (d * t + txt[i]) % q; 
	} 

	// Slide the pattern over text one by one 
	for (i = 0; i <= N - M; i++) 
	{ 

		// Check the hash values of current window of text 
		// and pattern. If the hash values match then only 
		// check for characters on by one 
		if ( p == t ) 
		{ 
			/* Check for characters one by one */
			for (j = 0; j < M; j++) 
			{ 
				if (txt[i+j] != pat[j]) 
					break; 
			} 

			// if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1] 
			if (j == M) 
				cout<<"Pattern found at index "<< i<<endl; 
		} 

		// Calculate hash value for next window of text: Remove 
		// leading digit, add trailing digit 
		if ( i < N-M ) 
		{ 
			t = (d*(t - txt[i]*h) + txt[i+M])%q; 

			// We might get negative value of t, converting it 
			// to positive 
			if (t < 0) 
			t = (t + q); 
		} 
	} 
} 

/* Driver code */
int main() 
{ 
	char txt[] = "GEEKS FOR GEEKS"; 
	char pat[] = "GEEK"; 
	int q = 101; // A prime number 
	search(pat, txt, q); 
	return 0; 
} 
```
## Above one is a blog (above algoirthms is a searching/matching pattern in the text using hash function)


#### [Z function](https://leetcode.com/problems/implement-strstr/)

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
                
        int m = haystack.size(), n = needle.size();
        
        // if needle is empty string then it is present in 0th index itself
        if(needle.size() == 0) return 0;
        
        // if haystack is empty then needle is not present at all
        if(haystack.size() == 0) return -1;
        
        for(int i = 0; i <= m - n; i++) {
            int j = 0;
            
            for( ; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            
            if(j==n){
                return i;
            }
        }
        return -1;
    }
};
``` 

#### [KMP algorithm](https://youtu.be/lhhqbGH7Pao)

```cpp

class Solution {
    
private:
    vector<int> prefix_array(string s){
        int n = s.size();
        vector<int> answer(n);
        
        answer[0] = 0;
        
        for(int i = 1; i < n; i++) {
            int j = answer[i-1];
            
            while(j > 0 && s[i] != s[j])
                j = answer[j-1];
            
            if(s[i] == s[j])
                j++;
            
            answer[i] = j;
        }
        
        return answer;
    }
public:
    int strStr(string haystack, string needle) {
        
        
        int m = haystack.size(), n = needle.size();
        
        if(needle.size() == 0) return 0;
        
        if(haystack.size() == 0) return -1;
        
        vector<int> prefix = prefix_array(needle);
        
        
        int pos = -1;
        int i = 0, j = 0;
        
        while(i < haystack.size()) {
            
            if(haystack[i] == needle[j]){
                j++;
                i++;
            }
            else{
                if(j!=0) {
                    j = prefix[j-1];
                }
                else{
                    i++;
                }
            }
            
            if (j == needle.size()){
                pos = i - needle.size();
                return pos;
            }
                
        }
        return -1;
    }
};

```

#### [Minimum characters required to make a strng palindromic](https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/)

#### [BLOG OF GFG FOR LOGIC](https://www.geeksforgeeks.org/minimum-characters-added-front-make-string-palindrome/)

#### main logic is reverse the given string concat with itself by adding a special character in between
#### then calculate prefix array for that
#### final answer will be last value is string size minus last value in the prefix array


#### [DP solutino of Aditya verma](https://www.youtube.com/watch?v=AEcRW4ylm_c)

### there is a DP solution too but for now i have gone with KMP as the time is Order of n and space is n
### for preix array


```cpp

vector<int> prefix_array(string s){

    int n = s.size();

    vector<int> ans(n);

    ans[0] = 0;

    for(int i = 1; i < n; i++) {

        int j = ans[i-1];

        while(j > 0 && s[i] != s[j])
            j = ans[j-1];

        if(s[i] == s[j])
            j++;
        ans[i] = j;
    }

    return ans;
}


int Solution::solve(string A) {

    string reverse_string = A;
    reverse(reverse_string.begin(), reverse_string.end());

    string concat =  A + "$" + reverse_string;

    vector<int> prefix = prefix_array(concat);

    return A.size() - prefix.back();
}

``` 

#### [Check if given 2 string are anagram or not](https://leetcode.com/problems/valid-anagram/)

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(), t.end());
        return  s == t ;
    }
};

```

#### above of nlogn solution as it is sorting below is order of n solution

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        int counts[26] = {0};
        for (int i = 0; i < n; i++) { 
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (counts[i]) return false;
        return true;
    }
};
```


#### [count and say](https://leetcode.com/problems/count-and-say/)
#### [To understand question clearly read this you will also find the answer here in python](https://leetcode.com/problems/count-and-say/discuss/201832/It's-a-good-question-let-me-explain-it)

#### trace the function again adarsh, you don't know the complete intuition yet

```cpp

class Solution {
private:
    string count(string s){
        char c = s[0];
        
        int count = 1;
        
        string result = "";
        
        for(int i = 1; i < s.size(); i++) {
            if (s[i] == c){
                count++;
            }
            else{
                result = result + to_string(count) + c;
                c = s[i];
                count = 1;
            }
        }
        
        result = result + to_string(count) + c;
        
        return result;
    }
    
public:
    string countAndSay(int n) {
        if (n == 1) 
            return "1";
        
        return count(countAndSay(n-1));
    }
};
```

#### iterative version of the code

```cpp

class Solution {
public:
    string countAndSay(int n) {
        string result = "1",current;
        while(--n){
            current = "";
            for(int i=0;i<result.size();i++){
                int count = 1;
                while(i < result.size()-1 && result[i] == result[i+1]){
                    count++;
                    i++;
                }
                current +=  to_string(count) + result[i] ;
            }
            result = current;
        }
        return result;
    }
};
```

#### [Compare version numbers](https://leetcode.com/problems/compare-version-numbers/)

#### [Solution in leetcode blog](https://leetcode.com/problems/compare-version-numbers/discuss/50767/My-2ms-easy-solution-with-CC%2B%2B)

```cpp

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0; 
        int j = 0;
        int n1 = version1.size(); 
        int n2 = version2.size();

        int num1 = 0;
        int num2 = 0;
        while(i<n1 || j<n2)
        {
            while(i<n1 && version1[i]!='.'){
                num1 = num1*10+(version1[i]-'0');
                i++;
            }

            while(j<n2 && version2[j]!='.'){
                num2 = num2*10+(version2[j]-'0');;
                j++;
            }

            if(num1>num2) return 1;
            else if(num1 < num2) return -1;

            num1 = 0;
            num2 = 0;
            i++;
            j++;
        }

        return 0;
    }
};

```



#### [Binary Tree Representation in cpp direct video](https://youtu.be/ctCpP0RFDFc?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk)

```cpp


struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
}

// for creating the tree

int main(){

    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(5);
}


```


#### [Inoder Traversal of the binary tree](https://leetcode.com/problems/binary-tree-inorder-traversal/)
#### [video solution for recursive code](https://www.youtube.com/watch?v=Z_NEgBgbRVI&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=7)

#### Recursive code

```cpp

void inorder(node){

    if (node == NULL) 
        return;

    inorder(node->left);
    print(node->data);
    inorder(node->right);
}

```

#### Inorder to return the array we can code as below

```cpp

class Solution {
private:
    void inorder(TreeNode* root, vector<int>& answer){
        if(root == NULL) {
            return;
        }
        
        inorder(root->left, answer);
        answer.push_back(root->val);
        inorder(root->right, answer);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        
        inorder(root, answer);
        
        return answer;
    }
};

```


#### [Video solution for the iterative version](https://www.youtube.com/watch?v=lxTGsVXjwvM&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=12)

```cpp


vector<int> inorderTraversal(TreeNode* root) {

    stack<TreeNode*> st;

    TreeNode* node = root;
    vector<int> inorder;

    while(true) {
        if(node != NULL) {
            st.push(node);
            node = node->left;
        }

        else{
            if(st.empty() == true) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->val);
            node = node->right;
        }
    }
    
    return inorder;
}
```

#### this version of traversal is called Morris traversal is uses a concept called threaded binary tree
#### [Video solution for morris traversal](https://youtu.be/80Zug6D1_r4?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk)

```cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> inorder;
        TreeNode* cur= root;
        
        while(cur != NULL) {
            if(cur->left == NULL) {
                inorder.push_back(cur->val);
                cur = cur->right;
            }
            
            else{
                // go to left and go to right most guy
                TreeNode* prev = cur->left;
                
                while(prev->right && prev->right != cur){
                    prev = prev->right;
                }
                
                if(prev->right == NULL){
                    prev->right = cur;
                    cur = cur->left;
                }
                else{
                    prev->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        
        return inorder;
    }
};

```

#### [Preorder traversal of the binary tree](https://leetcode.com/problems/binary-tree-preorder-traversal/)


#### Recursive code for the preorder traversal

```cpp
class Solution {
    
private:
        void preorder(TreeNode* root, vector<int>& answer){
        if(root == NULL) {
            return;
        }
        answer.push_back(root->val);
        preorder(root->left, answer);
        preorder(root->right, answer);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;
        
        preorder(root, answer);
        return answer;
    }
};
```


#### Iterative code for the preorder


```cpp


class Solution {

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;
        
        if(root==NULL) return answer;
        
        stack<TreeNode*> st;
        
        st.push(root);
        
        while(!st.empty()){
            
            TreeNode* cur = st.top();
            answer.push_back(cur->val);
            st.pop();
            
            if(cur->right != NULL){
                st.push(cur->right);
            }
            
            if(cur->left != NULL){
                st.push(cur->left);
            }
        }
        
        return answer;
    }
};


```


#### Morris traversal for preorder

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> preorder;
        TreeNode* cur= root;
        
        while(cur != NULL) {
            if(cur->left == NULL) {
                preorder.push_back(cur->val);
                cur = cur->right;
            }
            
            else{
                // go to left and go to right most guy
                TreeNode* prev = cur->left;
                
                while(prev->right && prev->right != cur){
                    prev = prev->right;
                }
                
                // push into the vector when the thread is connected for last right to the current node
                if(prev->right == NULL){
                    prev->right = cur;
                    preorder.push_back(cur->val);
                    cur = cur->left;
                }
                else{
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        
        return preorder;
    }
};
```


#### [Post order traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/)
#### Recursive approach for postorder traversal

```cpp
class Solution {
private:
    void postorder(TreeNode* root, vector<int>& answer){
        if(root == NULL){
            return;
        }
        
        postorder(root->left, answer);
        postorder(root->right, answer);
        answer.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> answer;
        
        postorder(root, answer);
        return answer;
    }
};
```


#### [Left view / Right view of a binary tree](https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1)
#### [video solution](https://www.youtube.com/watch?v=KV4mRzTjlAk&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=26)

```cpp

class Solution{

    vector<int> rightSideVide(TreeNode* root) {
        vector<int> res;

        recursion(root, 0, res);

        return res;
    }


    void recursion(TreeNode* root, int level, vector<int>& res){

        if(root == NULL) return;
        if(res.size() == level) res.push_back(root->val);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);

        // for left view of the binary tree only the last recursion calls are swapped
    }
};

```


#### Vertical order traversal of a binary tree
#### [Video Solution](https://youtu.be/q_a6lpbKJdw?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk)

```cpp

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> todo;

        todo.push({root, {0,0}});

        while(!todo.empty()){

            auto p = todo.front();
            todo.pop();

            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;

            nodes[x][y].insert(node->val);

            if(node->left){
                todo.push({node->left, {x-1, y+1}});
            }

            if(node->right){
                todo.push({node->right, {x+1, y+1}});
            }
        }

        vector<vector<int>> ans;
        for(auto p: nodes) {
            vector<int> col;
            for(auto q: p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};


```


#### [Bottom view of the binary treee](https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1)
#### [video solution](https://www.youtube.com/watch?v=0FtVY6I4pB8&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=25)

#### the main logic behind this question is we have to do first the vertical order traversal and on every vertical line we need to print the last node
#### if there are multiple go with the right one or as per the interviewer

```cpp

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans; 
        if(root == NULL) return ans; 

        map<int,int> mpp; 
        queue<pair<Node*, int>> q; 

        q.push({root, 0}); 

        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 

            Node* node = it.first; 
            int line = it.second; 
            mpp[line] = node->data; 
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans;  
    }
};



```


#### [Top view of a binary tree](https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1_)
#### [video solution](https://www.youtube.com/watch?v=Et9OCDNvJ78&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=23)

```cpp


class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            Node* node = it.first; 
            int line = it.second; 
            if(mpp.find(line) == mpp.end()) mpp[line] = node->data; 
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans; 
    }

};


```

#### [Zig Zag or spiral traversal of a tree](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
#### [video solution](https://www.youtube.com/watch?v=3OXWEdlIGl4&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=21)

```cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if(root == NULL) return result;
        
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        
        bool leftToRight = true;
        
        while(! nodesQueue.empty()){
            
            int size = nodesQueue.size();
            vector<int> row(size);
            
            for(int i = 0; i < size; i++) {
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();
                
                //find the position to fill nodes value
                int index = (leftToRight) ? i : size - 1 - i;
                row[index] =  node->val;
                
                if(node->left){
                    nodesQueue.push(node->left);
                }
                if(node->right){
                    nodesQueue.push(node->right);
                }
            }
            
            //after this level
            leftToRight = !leftToRight;
            result.push_back(row);
        }
        
        return result;
    }
};

```

#### [Height or maximum depth of the binary tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
#### [Video solution](https://youtu.be/eD3tmO66aBA?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk)


```cpp

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0; 
        
        int lh = maxDepth(root->left); 
        int rh = maxDepth(root->right); 
        
        return 1 + max(lh, rh); 
    }
}; 


```

#### [Diameter of the binary tree](https://leetcode.com/problems/diameter-of-binary-tree/)
#### It is the longest path between any two nodes
#### It may pass through the root but it is not mandatory to pass the pass from root in order to consider it as diameter

#### [video Solution](https://youtu.be/Rezetez59Nk?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk)

```cpp

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
private:
    int height(TreeNode* node, int& diameter) {
        if (!node) {
            return 0;
        }
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }
};


```

#### [Balanced binary tree](https://leetcode.com/problems/balanced-binary-tree/)
#### [video solution](https://youtu.be/Yt50Jfbd8Po?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk)

```cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
    
    
    int dfsHeight(TreeNode* root){
        if(root == NULL) return 0;
        
        int leftHeight = dfsHeight(root->left);
        if (leftHeight == -1) return -1;
        
        int rightHeight = dfsHeight(root->right);
        if(rightHeight == -1) return -1;
        
        if(abs(leftHeight - rightHeight) > 1) return -1;
        
        return max(leftHeight, rightHeight) + 1;
        
    }
};

```


#### [Lowest common ancestor in a binary tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)
#### [video solution](https://youtu.be/_-QHfMDde90?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk)

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case 
        if(root == NULL || root == p || root == q) {
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right,p, q);
        
        if(left == NULL){
            return right;
        }
        
        else if (right == NULL){
            return left;   
        }
        
        else{
            return root;
        }
    }
};
```

#### [check if two trees are identical or not](https://leetcode.com/problems/same-tree/)
#### [Video solution](https://www.youtube.com/watch?v=BhuvF_-PWS0&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=19)

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p == NULL || q == NULL)
            return (p == q);
        
        return (p->val == q->val) && isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
    }
};
```

#### [Binary tree maximum path sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)
#### [Video solution](https://youtu.be/WszrfSwMz58?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk)


```cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }
    
    int maxPathDown(TreeNode* node, int& maxi){
        if(node == NULL) return 0;
        
        // get sum of both left and right sub tree
        // if negative sum is there or nodes are there ignore them and take them as zero
        int left = max(0, maxPathDown(node->left, maxi));
        int right = max(0, maxPathDown(node->right, maxi));
        
        // update maximum
        maxi = max(maxi, left + right + node->val);
        
        return max(left, right) + node->val;
    }
};


```


## Construct a unique binary trees from the given traversals
#### [Video solution](https://youtu.be/9GMECGQgWrQ?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk)

#### we cannot construct a unique binary tree with only preorder and postorder because for the given sequence we can have multiple binary trees which satisfies the conditions

#### we can construct a unique binary tree using inorder & preorder and we can also construct a binary tree using inorder & postorder

#### something like inorder is very very important inorder to construct a unique binary tree because it gives a clear cut idea that what is on the left of the root and 
#### what is on the right of the root which is really important to create a unique binary tree






#### [construct binary tree from inorder and preorder](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)
#### [Video solution](https://youtu.be/aZNaLrVebKQ?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk)

```cpp

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap; 

        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
        return root;
    }
   TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> &inMap) {
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

        return root;
    }
};

```



#### [construct binary tree from inroder and postorder](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)
#### [video solution](https://youtu.be/LgLRTaEMRVc?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk)

```cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if(inorder.size() != postorder.size()) {
            return NULL;
        }
        
        map<int,int> hm;
        
        for(int i = 0; i < inorder.size(); i++) {
            hm[inorder[i]] = i;
        }
        
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, hm);
    }
    
private:
    TreeNode* buildTree(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, map<int,int>& hm){
        
        if(ps > pe || is > ie) return NULL;
        
        TreeNode* root = new TreeNode(postorder[pe]);
        
        int inRoot = hm[postorder[pe]];
        int numsLeft = inRoot - is;
        
        root->left = buildTree(inorder, is, inRoot - 1, postorder, ps, ps+numsLeft -1, hm);
        root->right = buildTree(inorder, inRoot+1, ie, postorder, ps+numsLeft, pe-1, hm);
        
        return root;
    }
};

```


#### [Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)
#### [video solution](https://youtu.be/nKggNAiEpBE?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk)

```cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        return root == NULL || isSymmetricHelp(root->left, root->right);
    }
    
    bool isSymmetricHelp(TreeNode* left, TreeNode* right){
        
        if(left == NULL || right == NULL){
            return left == right;
        }
        
        if(left->val != right->val) return false;
        
        return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
    }
};

```

#### [Flatten a binary tree to linked list](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)
#### [video solutoin](https://youtu.be/sWf7k1x9XR4?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk)

#### basic code version of the solution is

```cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *prev = NULL;

    void flatten(TreeNode* root) {
        
        if(root == NULL){
            return;
        }
        
        flatten(root->right);
        flatten(root->left);
        
        root->right = prev;
        root->left = NULL;
        
        prev = root;
    }
};

```

#### Stack based approach

```cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        
        stack<TreeNode*> st;
        
        if (root == NULL) return;
        
        st.push(root);
        
        while(!st.empty()) {
            
            TreeNode* cur = st.top();
            st.pop();
            
            if( cur->right){
                st.push(cur->right);
            }
            
            if(cur->left ){
                st.push(cur->left);
            }
            
            if(!st.empty()){
                cur->right = st.top();
            }
            
            cur->left = NULL;
        }

        
    }
};

```


#### Moores traversal with order of 1 space

```cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
		while (cur)
		{
			if(cur->left)
			{
				TreeNode* pre = cur->left;
				while(pre->right)
				{
					pre = pre->right;
				}
				pre->right = cur->right;
				cur->right = cur->left;
				cur->left = NULL;
			}
			cur = cur->right;
		}
    }
};


```

#### [Mirror of a binary tree](https://practice.geeksforgeeks.org/problems/mirror-tree/1)


```cpp

void mirror(struct Node* node) {
    // code here
    if(node == NULL) return;
    
    
    struct Node *temp;
    
    mirror(node->left);
    mirror(node->right);
    
    temp = node->left;
    node->left = node->right;
    node->right = temp;    
    
}

```

#### [Populate next right pointer of each node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)
#### [Blog solution](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/discuss/37503/C%2B%2B-IterativeRecursive)


```cpp

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(root == NULL) return root;
        
        Node* pre = root;
        Node* cur = NULL;
        
        while(pre->left){
            cur = pre;
            
            while(cur){
                cur->left->next = cur->right;
                
                if(cur->next) cur->right->next = cur->next->left;
                
                cur = cur->next;
            }
            
            pre = pre->left;
        }
        
        return root;
    }
};

```

#### [Search in a binary search tree](https://leetcode.com/problems/search-in-a-binary-search-tree/)
#### [video solution](https://youtu.be/KcNt6v_56cc?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk)

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        while(root != NULL && root->val != val){
            root = val< root->val ? root->left : root->right;
        }
        return root;
    }
};
```

#### [convert sorted array to binary search tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)
#### [blog solution](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/discuss/35242/16-ms-C%2B%2B-solution)

```cpp
class Solution {
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end){
        if(end<=start) return NULL; 
        int midIdx=(end+start)/2;
        TreeNode* root=new TreeNode(nums[midIdx]);
        root->left=sortedArrayToBST(nums, start, midIdx);
        root->right=sortedArrayToBST(nums, midIdx+1,end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0,nums.size());
    }
};
```

#### [check if a binary tree is BST or not](https://leetcode.com/problems/validate-binary-search-tree/)
#### [video solution](https://www.youtube.com/watch?v=f-sj7I5oXEI&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=47)

```cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        return isValidBST(root, INT_MIN, INT_MAX);
    }
    
    bool isValidBST(TreeNode* root, long long minVal, long long maxVal){
        
        if(root == NULL)   return true;
        
        if(root->val >= maxVal || root->val <= minVal) return false;
        
        return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
    }
    
    
};

```

#### [Lowest Common Ancestor in Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)
#### [video solution](https://www.youtube.com/watch?v=cX_kPV_foZc&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=48)

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            
        if(root == NULL) return NULL;
        
        int curr = root->val;
        
        if (curr < p->val && curr < q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        
        if(curr > p->val && curr > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        
        return root;
    }
};


```

#### Inorder Successor and predessor in BST the problem is in premium that is why i am not attaching the link

```cpp

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = NULL;
        
        while (root != NULL) {
            
            if (p->val >= root->val) {
                root = root->right;
            } else {
                successor = root;
                root = root->left;
            }
        }
        
        return successor;
    }
};

```


#### [Floor in BST](https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos)
#### for the given value find the value in the tree which is smaler than or equal to the given value
#### [video solution](https://youtu.be/xm_W1ub-K-w?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk)

```cpp


int floorBST(TreeNode<int>* root, int key) {

    int floor = -1;
    while(root){

        if(root->val == key) {
            floor = root->val;
            return floor;
        }

        if(key > root->val){
            floor = root->val;
            root = root->right;
        }

        else{
            root = root->left;
        }
    }
}



```

#### [Ceil in BST](https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos)

#### [video solution](https://youtu.be/KSsk8AhdOZA?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk)

```cpp

 int findCeil(BinaryTreeNode<int> *root, int key){

	int ceil = -1; 
    while (root) {

        if (root->data == key) {
            ceil = root->data;
            return ceil;
        }
 
        if (key > root->data) {
            root = root->right;
        }
        else {
            ceil = root->data; 
            root = root->left;
        }
    }
    return ceil; 
}

```

#### [Find kth smallest in BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)
#### [Video solutoin](https://youtu.be/9TJYWh0adfk?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk)

#### kth largest is also same logic as kth smallest 
#### find the total nodes and kth largest will be n-kth smallest
#### do inorder traversal and maintain the counter thats it

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        
        TreeNode* node = root;
        
        int count = 0;
        
        while(true){
            
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            
            else{
                if(st.empty()){
                    break;
                }
                
                node = st.top();
                st.pop();
                count++;
                
                if(count == k) return node->val;
                node = node->right;
            }
        }
        return -1;
    }
};


```


#### [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/submissions/)
#### [Video Solution](https://youtu.be/D2jMcmxU4bs?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk)


```cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> myStack;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* tempNode = myStack.top();
        myStack.pop();
        pushAll(tempNode->right);
        return tempNode->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
private:
    void pushAll(TreeNode* node){
        for( ;  node != NULL; myStack.push(node), node = node->left);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */



```

# from here watch strivers video again 
# due to lack of internet i am trying to learn from discussions

#### [Check if there are a pair of numbers in the BST whose sum is K](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)
#### [Video Solution](https://youtu.be/ssL3sHwPeb4?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk)

```cpp

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, root, k);
    }
    
    bool dfs(TreeNode* root, TreeNode* cur, int k){
        if (cur == NULL) return false;
        
        return search(root, cur, k - cur->val) || dfs(root, cur->left, k) || dfs(root, cur->right, k);
    }
    
    bool search(TreeNode* root, TreeNode* cur, int value) {
            
        if(root == NULL) return false;
        return (root->val == value) && (root != cur) 
            || (root->val < value) && search(root->right, cur, value) 
                || (root->val > value) && search(root->left, cur, value);
    }
};

```

#### [Maximum sum BST in binary tree](https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/)
#### [blog solution](https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/discuss/990802/C%2B%2B-Recursive-faster-than-99-with-explanation)


```cpp

class Solution {
    struct S {
        bool isBST;
        int minVal, maxVal, sum;
    };
    
    S helper(TreeNode *node, int &res) {
        if (!node) {
            return { true, INT_MAX, INT_MIN, 0 };
        }
        S l = helper(node->left, res);
        S r = helper(node->right, res);
        if (l.isBST && r.isBST && l.maxVal < node->val && r.minVal > node->val) {
            int sum = l.sum + r.sum + node->val;
            res = max(res, sum);
            return { true, min(l.minVal, node->val), max(r.maxVal, node->val), sum };
        } else {
            return { false, 0, 0, 0 };
        }
    }
public:
    int maxSumBST(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
};

```

#### [Serialize and deserialize binary tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)
#### [Video Solution](https://www.youtube.com/watch?v=-YbXySKJsX8&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=37)

```cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(!root) return "";
        
        string s = "";
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* curNode = q.front();
            q.pop();
            
            if(curNode == NULL) s.append("#,");
            else s.append(to_string(curNode->val) + ',');
            
            if(curNode != NULL) {
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.size() == 0) return NULL;
        stringstream s(data); 
        string str;
        // extract data from s to str upto comma ,
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            
            TreeNode* node = q.front();
            q.pop();
            
            getline(s, str, ',');
            if(str == "#") {
                node->left = NULL;
            }
            
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            
            getline(s, str, ',');
            if(str == "#") {
                node->right = NULL;
            }
            
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

```

#### Largest BST in Binary Tree
#### [Video Solution](https://youtu.be/X0oXMdtUDwo)

```cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class NodeValue {
public:
    int maxNode, minNode, maxSize;
    
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution {
private:
    NodeValue largestBSTSubtreeHelper(TreeNode* root) {
        // An empty tree is a BST of size 0.
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        
        // Get values from left and right subtree of current tree.
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        
        // Current node is greater than max in left AND smaller than min in right, it is a BST.
        if (left.maxNode < root->val && root->val < right.minNode) {
            // It is a BST.
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), 
                            left.maxSize + right.maxSize + 1);
        }
        
        // Otherwise, return [-inf, inf] so that parent can't be valid BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
public:
    int largestBSTSubtree(TreeNode* root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};

```
 

#### [Binary Tree to linked list](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)
#### [Video solution](https://www.youtube.com/watch?v=sWf7k1x9XR4)

#### 1st approach

```cpp

TreeNode* prev = NULL;

flatten(TreeNode* node) {

    if(node == NULL) 
        return;

    flatten(node->right);
    flatten(node->left);

    node->right = prev;
    node->left = NULL;

    prev = node;
}

```

#### 2nd approach

```cpp

st.push(root);

while( !st.empty()){
    
    cur = st.top();
    st.pop();

    if(cur->right)
        st.push(cur->right);
    
    if(cur->left)
        st.push(cur->left);

    if(!st.empty())
        cur->right = st.top();

    cur->left = NULL;
}

```

#### 3rd approach using Morris traversal

```cpp

TreeNode* cur = root;
while(cur != NULL) {
    if(cur->left != NULL) {
        prev = cur->left;
        
        while( prev->right) 
            prev = prev->right;

        prev->right = cur->right;
        cur->right = cur->left;

    }

    cur = cur->right;
}

```

## Morris traversal for inorder
## this is just for my practice

```cpp

vector<int> getInorder(TreeNode* root){

    vector<int> inorder;

    TreeNode* cur = root;

    while(cur != NULL){

        if(cur->left == NULL) {
            inorder.push_back(cur-val);
            cur = cur->right;
        }

        else{
            TreeNode* prev = cur->left;

            while(prev->right && prev->right != cur) {
                prev = prev->right;
            }

            if(prev->right == NULL) {
                prev->right = cur;
                cur = cur->left;
            }

            else{
                prev->right = NULL;
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }

    return inorder;
}


```

## for preorder using morris traversal

```cpp

vector<int> preorder(TreeNode* root){

    vector<int> preorder;
    TreeNode* cur = root;

    while(cur != NULL) {

        if(cur->left == NULL){
            preorder.push_back(cur->val);
            cur = cur->right;
        }

        else{

            TreeNode* prev = cur->left;

            while(prev->right != NULL && prev->right != cur) {
                prev = prev->right;
            }


            if(prev->right == NULL){
                prev->right = cur;
                preorder.push_back(cur->val);
                cur = cur->left;
            }

            else{
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }

    return preorder;
}

```

#### [Find median of data stream of running numbers](https://leetcode.com/problems/find-median-from-data-stream/)
#### [video solution of anuj bhayya](https://www.youtube.com/watch?v=Yv2jzDzYlp8)
 

```cpp
class MedianFinder {
private:
    priority_queue<int> firstQ; // max_heap for the first half
    priority_queue<int, std::vector<int>, std::greater<int>> secQ; // min heap for the second half
public:
//     MedianFinder() {
        
//     }
    
    void addNum(int num) {
        
        if(firstQ.empty() || (firstQ.top() > num))  {
            firstQ.push(num); // if it belongs to smaller half
        }
        
        else{
            secQ.push(num);
        }
        
        if(firstQ.size() > (secQ.size() + 1)) {
            secQ.push(firstQ.top());
            firstQ.pop();
        }
        
        else if(firstQ.size() + 1 < secQ.size()) {
            firstQ.push(secQ.top());
            secQ.pop();
        }
    }
    
    double findMedian() {
        if(firstQ.size() == secQ.size()) return firstQ.empty()?0:( (firstQ.top()+secQ.top())/2.0);
        else return (firstQ.size() > secQ.size())? firstQ.top():secQ.top(); 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
 ```

#### [Kth largest element in the stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/)
#### [Solution blog](https://leetcode.com/problems/kth-largest-element-in-a-stream/discuss/150609/C%2B%2B-super-easy-28ms-solution-beats-100!)
#### [Video solution](https://www.youtube.com/watch?v=j48e8ac7r20)


```cpp
class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            
            if(pq.size() > k) pq.pop();
        }
        
    }
    
    int add(int val) {
        pq.push(val);
        
        if(pq.size() > size)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
 ```


#### [Distinct numbers in a window](https://www.interviewbit.com/problems/distinct-numbers-in-window/)
#### [blog solution github](https://github.com/cruxrebels/InterviewBit/blob/master/HeapsAndMaps/DistinctNumbersInWindow.cpp)

#### [Video Solution](https://youtu.be/j48e8ac7r20)


```cpp
/*
You are given an array of N integers, A1, A2 ,…, AN and an integer K. Return the of count of distinct numbers in all windows of size K.

Formally, return an array of size N-K+1 where i’th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,…, Ai+k-1.

Note:
- If K > N, return empty array.

For example,

A=[1, 2, 1, 3, 4, 3] and K = 3

All windows of size K are

[1, 2, 1]
[2, 1, 3]
[1, 3, 4]
[3, 4, 3]

So, we return an array [2, 3, 3, 2].

https://www.interviewbit.com/problems/distinct-numbers-in-window/
*/

vector<int> Solution::dNums(vector<int> &A, int B) {
    auto n = A.size();
    vector<int> res;
    //if (B>n)              // This check will also work
    //    return res;
    assert(B<=n);   // if false then write a error message to stdout & calls abort
    
    unordered_map<int, int> m;
    for (auto i = 0; i<n; ++i)
    {
        ++m[A[i]];
        
        if (i-B+1>=0)
        {
            res.emplace_back(m.size());
            --m[A[i-B+1]];
            if (m[A[i-B+1]] == 0)
                m.erase(A[i-B+1]);
        }
    }
    return res;
    
    // More verbose solution
    /*for (auto i = 0; i<B; ++i)
    {
        if (m[A[i]] == 0)
            ++c;
        m[A[i]] += 1;
    }
    res.emplace_back(c);
    
    for (auto i = B; i<n; ++i)
    {
        if (m[A[i-B]] == 1)
            --c;
        m[A[i-B]] -= 1;
        
        if (m[A[i]] == 0)
            ++c;
        m[A[i]] += 1;
        res.emplace_back(c);
    }
    return res;*/
}

```

### Java bit better solution to understand

```java


void countDistinctElements(int a[], int k) {

	Map<Integer,Integer> map = new HashMap<>();
	
	for(int i = 0; i < k; i++) {
		// if present in map add 1 or keep value as 0 to the key
		map.put(a[i], map.getOrDefault(a[i],0) + 1);
	}
	
	print( map.size());
	
	for(int i = k; i < a.length; i++){
		
		if(map.get(a[i-k] == 1))
			// if frequency of element to be removed is 0 completely remove from the map
			map.remove(a[i-k]);
			
		else	
			// if frequency is higher than 1 then reduce its frequency by 1 
			map.put(a[i-k], map.get(a[i-k]) -1);
		
		// insert frquency of new element as 0 if not there else increase the value by 1	
		map.put(a[i], map.getOrDefault(a[i],0) + 1);
		
		print( map.size() );
	}
}



```


#### [kth largest element in the array](https://leetcode.com/problems/kth-largest-element-in-an-array/)
#### [blog solution](https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60294/Solution-explained)


#### heap based solution

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        
        for(int i = 0; i < nums.size(); i++) {
            pq.push(-1 * nums[i]);
            
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        return -1 * pq.top();
    }
};

```

#### using partial sort in cpp

```cpp

int findKthLargest(vector<int>& nums, int k) {

    partial_sort(nums.begin() , nums.begin() + nums.size() - k + 1, nums.end());
    return nums[nums.size() - k];

}

// or we can do as below

int findKthLargest(vector<int>& nums, int k){

    partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
    return nums[k-1];

}

```

#### using modified quick sort also known as quick select

```cpp

int findKthLargest(vector<int>& nums, int k) {

    int left = 0, right = nums.size() - 1, index = 0;
    while(1) {

        index = partition(nums, left, right);
        if(index == k-1) break;

        else if(index < k-1) left = index + 1;
        else right = index - 1;
    }

    return nums[index];
}

int partition(vector<int>& nums, int left, int right) { // hoare partition

    int pivot = nums[left], l = left+1, r = right;

    while(l <= r) {
        if (nums[l] < pivot && nums[r] > pivot ) swap(nums[l++], nums[r--]);

        if(nums[l] >= pivot) ++l;
        if(nums[r] <= pivot) --r;
    }

    swap(nums[left], nums[r]);
    return r;
}


```

#### [Flood fill algorithm](https://leetcode.com/problems/flood-fill/)
#### [video solution](https://youtu.be/aehEcTEPtCs)

```cpp

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] != newColor) 
            dfs(image, sr, sc, image[sr][sc], newColor);
        
        return image;
    }
    
private:
    void dfs(vector<vector<int>>& image, int i, int j, int oldColor, int newColor) {
        
        int n = image.size(), m = image[0].size();
        
        if(isNotOk(i, j, n, m, oldColor, newColor, image))
            return;
        
        image[i][j] = newColor;
        dfs(image, i + 1, j, oldColor, newColor);
        dfs(image, i - 1, j, oldColor, newColor);
        dfs(image, i, j + 1, oldColor, newColor);
        dfs(image, i, j - 1, oldColor, newColor)
        
    }
    
    bool isNotOk(int i, int j, int n, int m, int oldColor, int newColor, vector<vector<int>>& image){
        
        if(i >= n || i < 0 || j >= m || j < 0 )
            return true;
        
        if(image[i][j] != oldColor || image[i][j] == newColor) 
            return true;
        
        return false;
    }
};

```

#### [clone a graph](https://leetcode.com/problems/clone-graph/)
#### [Video solutoin](https://youtu.be/S931KMpiKmQ)

```cpp


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(node == NULL)
            return node;
        
        unordered_map<int, Node*> visited;
        
        return clone_node(node, visited);
        
    }
    
    Node* clone_node(Node* node, unordered_map<int, Node*> & visited){
        Node* new_node = new Node(node->val);
        
        visited.insert({node->val, new_node});
        
        for(Node* n: node->neighbors){
            auto it = visited.find(n->val);
            
            if(it == visited.end()){
                Node* cn = clone_node(n, visited);
                new_node->neighbors.push_back(cn);
            }
            else{
                new_node->neighbors.push_back(it->second);
            }
        }
        
        return new_node;
    }
};

```

#### [DFS](https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1)
#### [video solution](https://youtu.be/uDWljP2PGmU?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw)


```cpp

class Solution {

    void dfs(int node, vector<int>& vis, vector<int> adj[], vector<int>& answer) {
        
        answer.push_back(node);
        vis[node] = 1;
        
        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, adj, answer);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> answer;
        vector<int> vis(V, 0);
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, vis, adj, answer);
            }
        }
        
        return answer;
    }
};
```



#### [BFS](https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1)
#### [Video solution](https://www.youtube.com/watch?v=UeE67iCK2lQ&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=7)

```cpp

class Solution {
public:
	vector<int>bfsOfGraph(int V, vector<int> adj[]){
	    vector<int> bfs; 
	    vector<int> vis(V, 0); 
	    queue<int> q; 
	    q.push(0); 
	    vis[0] = 1; 
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop(); 
	        bfs.push_back(node); 
	        
	        for(auto it : adj[node]) {
	            if(!vis[it]) {
	                q.push(it); 
	                vis[it] = 1; 
	            }
	        }
	    }
	    
	    return bfs; 
	}
};

```

#### Detect a cycle in undirected graph using BFS
#### [Video Solution](https://www.youtube.com/watch?v=A8ko93TyOns&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=9)

```cpp

class Solution{

private:
    bool checkForCycle(int s, int V, vector<int> adj[], vector<int>& visited) {

        queue<pair<int,int>> q;

        visited[s] = true;
        q.push({s, -1});

        while( !q.empty()) {

            int node = q.front().first;
            int parent = q.front().second;

            q.pop();

            for(auto it: adj[node]) {
                if(!visited[it]) {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (parent != it) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[]) {

        vector<int> vis(V+1, 0);

        for(int i = 1; i <= V; i++) {
            if (!vis[i]){
                if (checkForCycle(i, V  , adj, vis)) return true;
            }
        }

        return false;
    }
};

```

#### Cycle detection using DFS
#### [Video Solution](https://youtu.be/Y9NFqI6Pzd4?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw)

```cpp

class Solution{

private:
    bool checkForCycle(int node, int parent, vector<int>& vis, vector<int> adj[]) {

        vis[node] = true;

        for(auto it: adj[node]) {
            if (vis[it] == 0) {
                if( checkForCycle(it , node, vis, adj)) return true;
            }
            else if( it != parent) return true;
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[]){

        vector<int> vis(V+1,0);

        for(int i = 1; i <= V; i++) {
            if (!vis[i]) {
                if (checkForCycle(i, -1, vis, adj)) return true;
            }
        }

        return false;
    }
};

// driver code

int main() {

    int test;
    cin >> test;

    while(test--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;

        bool ans = obj.isCycle(V, adj);

        if (ans)
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
}

```

#### [Cycle detection in directed graph using DFS](https://leetcode.com/problems/course-schedule/)
#### [Video solution](https://www.youtube.com/watch?v=uzVUw90ZFIg&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=13)

```cpp

class Solution{

private:
    bool checkCycle(int node, vector<int> adj[], int vis[], int dfsvis[]) {

        vis[node] = 1;
        dfsvis[node] = 1;

        for(auto it: adj[node]) {
            if(!vis[it]) {
                if ( checkCycle(it, adj, vis, dfsvis) ) 
                    return true;
            }
            
            else if (dfsvis[it]) 
                return true;
        }

        dfsvis[node] = 0;
        return false;
    }

public:
    bool isCyclic(int N, vector<int> adj[]) {
        int vis[N], dfsvis[N];
        memset(vis, 0, sizeof vis);
        memset(dfsvis, 0, sizeof dfsvis);

        for(int i = 0; i < N; i++){
            if(!vis[i]) {
                if (checkCycle(i, adj, vis, dfsvis)){
                    return true;
                }
            }
        }

        return false;
    }

};

```

#### [Detect cycle in Directed Graph using BFS(kahns' algorithm)](https://leetcode.com/problems/course-schedule/)
#### [Video solution](https://www.youtube.com/watch?v=V6GxfKDyLBM&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=15)

### This just a slight modification of the topological sort using BFS
### Go through it first and then come to this problem

```cpp

class Solution{

public:

    bool isCyclic(int N, vector<int> adj[]) {

        queue<int> q;
        vector<int> indegree(N,0);

        for(int i = 0; i < N; i++) {
            for(auto it: adj[i]) {
                indegree[it]++;
            }
        }

        for(int i = 0; i < N; i++) {
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            count++;

            for(auto it: adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        if (count == N) return false;

        return true;
    }
};

```


#### Topological Sorting using DFS
#### [Video Solution](https://www.youtube.com/watch?v=Yh6EFazXipA&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=13)

```cpp

class Solution{

private:
    void findTopoSort(int node, vector<int>& vis, stack<int>& st, vector<int> adj[]){

        vis[node] = 1;

        for(auto it: adj[node]) {
            if(!vis[it]) {
                findTopoSort(it, vis, st, adj);
            }
        }

        // after completion of the dfs traversal just push the node into the stack
        st.push(node);
    }


public:
    vector<int> toposort(int N, vector<int> adj[]) {

        stack<int> st;
        vector<int> vis(N, 0);

        for(int  i = 0; i < N; i++) {
            if(!vis[i]) {
                findTopoSort(i, vis, st, adj);
            }
        }

        vector<int> topo;

        while(!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }

        return topo;
    }
};

```


#### Topological sorting using BFS (Kahns' algorithm)
#### [Video Solution](https://www.youtube.com/watch?v=rZv_jHZva34&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=14)


```cpp

class Solution{

public:
    vector<int> topoSort(int N, vector<int> adj[]) {

        queue<int> q;
        vector<int> indegree(N, 0);

        for(int i = 0; i < N; i++) {
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        for(int i = 0; i < N; i++) {
            if( indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: adj[node]) {
                indegree[it]--;

                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return topo;
    }
};

```


#### [Number of Islands](https://leetcode.com/problems/number-of-islands/)

```cpp

class Solution {
public:
    bool inside(int i, int j, int  H, int W){
        return 0 <= i && i < H && 0 <= j && j < W;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int H = grid.size();
        
        if(H == 0) return 0;
        int W = grid[0].size();
        
        vector<vector<bool>> visited(H, vector<bool>(W));
        vector<pair<int,int>> directions {{1,0},{0,1},{-1,0},{0,-1}};
        int answer = 0;
        
        
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++) {
                if (!visited[i][j] && grid[i][j] == '1'){
                    
                    queue<pair<int,int>> q;
                    q.emplace(i,j);
                    answer++;
                    
                    visited[i][j] = true;
                    
                    while(!q.empty()) {
                        pair<int,int> p = q.front();
                        q.pop();
                        
                        for(pair<int,int> dir: directions){
                            int new_row = p.first + dir.first;
                            int new_col = p.second + dir.second;
                            
                            if(inside(new_row,new_col, H, W) && visited[new_row][new_col] == false && grid[new_row][new_col] == '1'){
                                q.emplace(new_row, new_col);
                                visited[new_row][new_col] = true;
                            }
                        }
                    }
                }
            }
        }
        return answer;
    }
};

```

#### [Bipartite graphs using BFS](https://leetcode.com/problems/is-graph-bipartite/)
#### [Video Solution](https://www.youtube.com/watch?v=nbgaEu-pvkU&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=10)


```cpp

#include<bits/stdc++.h>
using namespace std;

bool bipartiteBFS(int src, vector<int> adj[], int color[]) {

    queue<int> q;
    q.push(src);
    color[src] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node];
                q.push(it);
            }

            else if(color[it] == color[node]){
                return false;
            }
        }
    }

    return true;
}

bool checkBipartite(vector<int> adj[], int n) {

    int color[n];
    memset(color, -1, sizeof color);

    for(int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if(!bipartiteBFS(i, adj, color)) {
                return false;
            }
        }
    }

    return true;
}


int main() {

    int n, m;
    cin >> n >> m;

    vector<int> adj[n];
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(checkBipartite(adj, n)) {
        cout << "YES" << endl;
    }

    else {
        cout << "NO" << endl;
    }
    
    return 0;
}

```

#### [Bipartite graphs using DFS](https://leetcode.com/problems/is-graph-bipartite/)
#### [Video solution](https://www.youtube.com/watch?v=uC884ske2uQ&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=11)

```cpp

#include<bits/stdc++.h>
using namespace std;

bool bipartiteDFS(int node, vector<int> adj[], int color[]) {

    if(color[node] == -1) color[node] = 1;

    for(auto it: adj[node]) {
        if(color[it] == -1) {
            color[it] = 1 ^ color[node];

            if(!bipartiteDFS(it, adj, color)) {
                return false;
            }
            else if (color[it] == color[node]) return false;
        }
    }

    return true;
}


bool checkBipartite(vector<int> adj[], int n) {

    int color[n];
    memset(color, -1, sizeof color);

    for(int i = 0; i < N; i++) {
        if (color[i] == -1) {
            if (!bipartiteDFS(i, adj, color) {
                return false;
            }
        }
    }

    return true;
}


int main() {

    int n, m;
    cin >> n >> m;
    vector<int> adj[n];

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(checkBipartite(adj, n)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}




```

#### [Strongly connected components(KosaRaju's alogrithm)](https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/discuss/766485/kosaraju-algorithm-on)

#### [Video Solution](https://www.youtube.com/watch?v=V8qIqJxCioo&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=28)


```cpp

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, stack<int>& st, vector<int>& vis, vector<int> adj[]) {

    vis[node] = 1;
    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfs(it, st, vis, adj);
        }
    }

    st.push(node);
}

void revDfs(int node, vector<int>& vis, vector<int> tanspose[]){

    cout << node << " ";
    vis[node] = 1;

    for(auto it: transpose[node]) {
        if(!vis[it]){
            revDfs(it, vis, transpose);
        }
    }
}

int main() {

    int n, m;
    cin >> n >> m;
    
    vector<int> adj[n];

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    stack<int> st;
    vector<int> vis(n,0);

    for(int i = 0; i < n; i++) {
        if(!vis[i]){
            dfs(i, st, vis, adj);
        }
    }

    vector<int> tanspose[n];

    for(int i = 0; i < n; i++) {
        vis[i] = 0;
        for(auto it: adj[i]) {
            transpose[it].push_back(i);
        }
    }

    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(!vis[node]){
            cout << "SSC: ";
            revDfs(node, vis, transpose);
            cout << endl;
        }
    }

    return 0;
}

```

#### [Dijkstra's Algorithm](https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1)
#### [Video Solution](https://www.youtube.com/watch?v=jbhuqIASjoM&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=19)



```cpp

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> g[n+1] // 1 based indexing

    int a, b, wt;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> wt;
        g[a].push_back(make_pair(b,wt));
        g[b].push_back(make_pair(a,wt));
    }

    cin >> source;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // for min heap
    vector<int> distTo(n+1, INT_MAX);

    distTo[source] = 0;
    pq.push(make_pair(0, source));

    while(!pq.empty()){
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        vector<pair<int,int>>::iterator it;
        for(it = g[prev].begin(); it != g[prev].end(); it++) {
            int next = it->first;
            int nextDist = it->second;
            if(distTo[next] > distTo[prev] + nextDist){
                distTo[next] = distTo[prev] + nextDist;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }

    cout << "The distance from source, " << source << ", are :\n";
    for(int i = 1; i <= n; i++) cout << distTo[i] << " ";
    cout << endl;

    return 0;

}

```

#### [Bellman-Ford algorithm](https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0/)
#### [Video solution](https://www.youtube.com/watch?v=75yC1vbS8S8&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=29)



```cpp

#include<bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int v;
    int wt;

    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};


int main() {

    int n, m;
    cin >> n >> m;
    vector<node> edges;

    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }

    int src;
    cin >> src;

    int inf = 10000000;
    vector<int> dist(N, inf);

    dist[src] = 0;

    for(int i = 1; i <= n - 1; i++) {
        for(auto it: edges) {
            if(dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    int flag = 0;

    for(auto it: edges) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            cout << "Negative cycle found" << endl;
            flag = 1;
            break;
        }
    }

    if(!flag) {
        for(int i = 0; i < n; i++) {
            cout << i << " " << dist[i] << endl;
        }
    }

    return 0;
}

```


#### [Floyd Warshall algorith](https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1)

#### [Video solution](https://www.youtube.com/watch?v=nV_wOZnhbog)



```cpp


#include<bits/stdc++.h>
using namespace std;

void floyd_warshall(int graph[V][V]) {

    int dist[V][V];

    // assign all values of graph to all pairs sp
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    //find all pairs shortest path by trying all possible paths
    for(int k = 0; k < V; k++) { // try all intermediate nodes
        for(int i = 0; i < v; i++) { // try for all possible starting position
            for(int j = 0; j < V; j++){ // try for all possible ending position
                if(dist[i][j] == INT_MAX || dist[k][j] == INT_MAX) // skip if k is unreachable from i or j is unreachabel from k 
                    continue;
                else if(dist[i][k] + dist[k][j] < dist[i][j]) // check if new distance is shorter via vertex k
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // check for negative edge weight cycle

    for(int i = 0; i < v; i++) {
        if (dist[i][j] < 0 ) {
            cout << "Negative edge weight cycle is present " << endl;   
            return;
        }
    }

    // print shortest path graph
    // values printed as int max defines there is no path

    for(int i = 1; i < V; i++) {
        for(int j = 0; j < v; j++) {
            cout << i << " to " << j << " distance is " << dist[i][j] << endl;
        }
    }
}

int main() {

    int graph[V][V] = { { 0, 1, 4, INT_MAX, INT_MAX, INT_MAX},
                        { INT_MAX, 0, 4, 2, 7, INT_MAX},
                        {INT_MAX,INT_MAX, 0, 3, 4, INT_MAX},
                        { INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 4},
                        { INT_MAX, INT_MAX, INT_MAX, 3, 0, INT_MAX},
                        { INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5, 0} };

    floyd_warshall(graph);
    return 0;
}


```

### [Minimum spanning tree](https://www.youtube.com/watch?v=xsM8i0jVF1w&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=19)


#### [Minimum spanning tree using Prims algorithm](https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1)
#### [Video solution](https://www.youtube.com/watch?v=HnD676J56ak&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=20)

#### [video for implementation both brute and optimal](https://youtu.be/oNTsS8lGDHw?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw)


### Brute solution

```cpp


#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> adj[n];

    int a, b, wt;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> wt;
        adj[a].push_back({b, wt});
        adj[b].push_back({a, wt});
    }

    int  parent[n];
    int key[n];
    bool mstSet[n];

    for(int i = 0; i < n; i++) 
        key[i] = INT_MAX, mstSet[i] = false, parent[i] = -1;

    key[0] = 0;
    
    for(int count = 0; cout < N - 1; count++) {

        int mini = INT_MAX, u;

        for(int v = 0; v < n; v++) {
            if(mstSet[v] == false && key[v] < mini) {
                mini = key[v], u = v;
            }
        }

        mstSet[u] = true;

        for(auto it: adj[u]) {
            int v = it.first;
            int weight = it.second;

            if(mstSet[v] == false && weight < key[v]) {
                parent[v] = u, key[v] = weight;
            }
        }
    }

    
    for(int i = 1; i < n; i++)
        cout << parent[i] << "-" << i << endl;

    return 0;
}

```


### Optimal solution( using min heap or priority queue)


```cpp

#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,m;
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; 

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	
	
	int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});
    // Run the loop till all the nodes have been visited
    // because in the brute code we checked for mstSet[node] == false while computing the minimum
    // but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
    // hence its better to keep running till all the nodes have been taken. 
    // try the following case: 
    // Credits: Srejan Bera
    // 6 7 
    // 0 1 5 
    // 0 2 10 
    // 0 3 100 
    // 1 3 50 
    // 1 4 200
    // 3 4 250
    // 4 5 50 
    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
		        key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
            
    } 
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}

```

#### [Minimum spanning tree kruskals algorith](https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1)

#### [Video solution](https://www.youtube.com/watch?v=1KRmCzBl_mQ&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=24)


```cpp

#include<bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int v;
    int wt;

    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp( node a, node b) {
    return a.wt < b.wt;
}

int findParent(int u, vector<int>& parent) {
    if(u == parent[u]) return u;
    return findParent(parent[u], parent);
}

void unionn(int u, int v, vector<int>& parent, vector<int>& rank) {

    u = findParent(u, parent);
    v = findParent(v, parent);

    if(rank[u] < rank[v])
        parent[u] = v;

    else if(rank[v] < rank[u])
        parent[v] = u;

    else{
        parent[v] = u;
        rank[u]++;
    }
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<node> edges;

    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }

    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(n);
    for(int i = 0; i < n; i++) 
        parent[i] = i;

    vector<int> rank(n);

    int cost = 0;
    vector<pair<int,int>> mst;

    for(auto it: edges) {
        // check if two nodes are different components or not
        if(findPar(it.v, parent) != findPar(it.u, parent)) {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            unionn(it.u, it.v, parent, rank);
        }
    }

    cout << "cost " << endl;

    for(auto it: mst) cout << it.first << " - " << it.second << endl;
    return 0;
}


```


































































<hr style="border:2px solid blue"> </hr>







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
        // if freq[i] == 0
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

# Some simple useful tips

### Finding ceil of (a/b)

* (a + b - 1) / b equal to ceil(a / b) 



