#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& array, int target){
    int n = array.size();

    if (n==0){
        return -1;
    }

    int left = 0, right = n - 1;
    int first_num = array[0];
    bool target_big = target >= first_num;

    while(left <= right){
        int mid = left + (right - left)/2;
        int value = array[mid];

        if (value == target){
            return mid;
        }

        bool current_big = value >= first_num;        

        if (current_big == target_big){
            if (value < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        else{
            if(current_big){
                left = mid + 1;
            }

            else{
                right = mid - 1;
            }
        }

    }

    return -1;
}

int main(){
    int test;
    cin >> test;

    while(test--){
        int n;
        cin >> n;

        vector<int> array(n);
        for(int i = 0; i < n; i++){
            cin >> array[i];
        }

        int target;
        cin >> target;

        cout << search(array, target) << endl;
    }
}