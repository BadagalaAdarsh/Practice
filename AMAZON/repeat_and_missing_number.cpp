/*
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.
*/

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