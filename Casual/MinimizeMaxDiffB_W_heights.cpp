#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

// need to understand better from here

int min_difference(vector<int>& array, int k) {

    sort(array.begin(), array.end());
    int min_ele, max_ele;
    int result = array[int(array.size()) - 1] - array[0];
    int n = array.size();

    for(int i = 1; i < (int)array.size(); i++) {

        if(array[i] >= k && array[n-i] >= k) {
            max_ele = max(array[i - 1] + k, array[n - 1] - k);
            min_ele = min(array[0] + k, array[i] - k);

            result = min(result, max_ele - min_ele);
        }
    }

    return result;

}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test; 
    cin >> test;

    while(test--) {

        int n;
        cin >> n;

        vector<int> array(n);

        for(int i = 0; i < n; i++) cin >> array[i];

        int k;
        cin >> k;

        cout << min_difference(array,k) << endl;
    }
}