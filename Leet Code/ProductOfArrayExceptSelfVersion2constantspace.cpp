#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {

    int n = nums.size();
    int count_zero = 0;
    int total_product = 1, product_without_zero = 1;

    for(int num: nums){
        
        total_product *= num;
        if(num == 0){
            count_zero++;
        }
        else{
            product_without_zero *= num;
        }
    }

    vector<int> answer(n);

    if (total_product != 0){
            for(int i = 0; i < n; i++){
                answer[i] = total_product / nums[i];
            }
    }
    else if (count_zero == 1) {
        for(int i = 0; i < n ; i++){
            if (nums[i] == 0){
                answer[i] = product_without_zero;
            }
        }
    }

    else{
        // do nothing cause by default the value of vector is zero
    }

    return answer;
}

int main(){

    int test;
    cin >> test;

    while(test--){

        int n;
        cin >> n;

        vector<int> nums(n);

        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        vector<int> answer = productExceptSelf(nums);

        for(int i = 0; i < n; i++){
            cout << answer[i] << " " ;
        }
    }
}