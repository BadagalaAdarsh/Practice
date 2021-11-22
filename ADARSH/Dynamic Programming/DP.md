
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