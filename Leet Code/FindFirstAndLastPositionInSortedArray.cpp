#include<bits/stdc++.h>
using namespace std;

int binarysearch(vector<int>& array, int target){
    int n = array.size();
    int left = 0;
    int right = n - 1;
    int first = n;

    while(left <= right){
        int mid = left + (right - left)/2;

        if(array[mid] >= target){
            first = mid;
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }

    return first;   
}

pair<int,int> searchRange(vector<int>& array, int target){

    int first = binarysearch(array,target);
    int last = binarysearch(array, target+1) - 1;
    //cout << first << " " << last << endl;
    if (first <= last ){
        return {first,last};
    }
    return {-1,-1};
}

int main(){

    int test;
    scanf("%d",&test);
    //cout << bitset<8>(test);

    while(test--){
        int n;
        scanf("%d",&n);

        vector<int> array(n);
        for(int i = 0; i < n ; i++){
            scanf("%d",&array[i]);
        }

        int target;
        cin >> target;

        pair<int,int> answer = searchRange(array, target);

        printf("%d %d\n",answer.first, answer.second);
    }
}