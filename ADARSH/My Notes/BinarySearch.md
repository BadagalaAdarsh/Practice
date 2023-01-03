# Binary Search

* Basic Template for binary search in cpp

```cpp
int binarySearch(vector<int>& nums, int target) {

    if (nums.size() == 0 ) 
        return -1;

    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        // below formula is to prevent overflow
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    // End condition
    return -1;
}
```

## Guess Number

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns 3 possible results:

-1: The number I picked is lower than your guess (i.e. pick < num).
1: The number I picked is higher than your guess (i.e. pick > num).
0: The number I picked is equal to your guess (i.e. pick == num).

Return the number that I picked

``` cpp
int guessnumber(int n) {
    int low = 1;
    int high = n;

    while (low <= hight) {
        int mid = low + (high - low ) / 2;
        int rest = guess(mid); // guess is a function which returns 
        // 0, -1 or 1 based on the condition given in question

        if (res == 0) return mid;
        else if (res < 0 ) high = mid - 1;
        else low = mid + 1;
    }

    return -1;
}
```

## Search in a Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

* Here we can do one thing which is first to find the shfiting point
* that first we will calculate the mid and somehow we need to decide whether it is rotated part or the actual part
* this can be done by comparing the mid with the first element
* if current element is greater or equal than the first element then it is in the bigger part
* that is if mid >= first then we are still in the greater part and we need to move right to find the miniumum
* if mid is smaller than the first one then we need to go left to find the minimum element in the array
* second part after finding the split is we can decide in which part the target is and then we can implement the standard binary search
* this approach will be 2 * log (n)

#### Slightly better approach for solving the above problem 

* below implementation is something better than what is discussed above
* it will try to do it in log(n) timing

```cpp
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
```

## First Bad Version

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

```cpp

int firstBadVersion(int n) {
    int low = 1, high = n;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if( isBadVersion(mid)){
            // if mid is true the there are 2 cases
            // either this is first bad version
            // or it is towards left
            result = mid;
            high = mid -1;
        }

        else{
            // if it is good 
            // then we are sure that it is in the right part
            low = mid + 1;
        }
    }
    return mid;
}
```

