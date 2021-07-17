#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& array) {
    int low = 0;
    int high = array.size() - 1;

    while (low < high) {
        if (array[low] < array[high]) {
            return array[low];
        }

        int mid = low + (high - low) / 2;

        if (array[mid] >= low) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    return array[low];
}

int main(){
    int test;
    cin >> test;

    while(test--) {
        int n ;
        cin >> n;

        vector<int> array(n);
        for(int i = 0; i < n; i++) {
            cin >> array[i];
        }
        
        cout << findMin(array) << endl;
    }
}