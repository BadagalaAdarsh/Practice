/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n
*/

// Solution: https://www.youtube.com/watch?v=hVl2b3bLzBw&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=4



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