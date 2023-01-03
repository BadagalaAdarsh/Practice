#include<bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> array(n);
    ll sum = 0;
    ll answer = 0;
    for(int i = 0; i  < n; i++) cin >> array[i], sum += array[i];


    // iterate over all 2 power n sets
    for(int i = 0; i < (1 << n); i++) {
        ll currentSum = 0;


        for(int j = 0; j < n; j++) {
            
            // check if jth bit is set or not 
            // if it is set then add it to the current sum
            if (i & (1 << j))
                currentSum += array[j];
        }

        if (currentSum <= sum/2) 
            answer = max(answer, currentSum);
    }

    cout << sum - 2* answer;
}

