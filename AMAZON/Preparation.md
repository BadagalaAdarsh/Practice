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

