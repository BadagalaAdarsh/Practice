/*
Given an integer array arr, count elements x such that x + 1 is also in arr
if there are duplicates in array , count them  separately

arr=[1,2,3]
output 2 

1 has 2 and 2 has 3
*/

#include<bits/stdc++.h>
using namespace std;

int countElements(vector<int>& arr){
    // you can also do the same by sorting the elements
    // even the time complexity of both of this is same
    // sorting is much faster when compared with the below solution
    set<int> array_set;

    for(int number: arr){
        array_set.insert(number);
    }

    int count = 0;

    for(int number: arr){
        if(array_set.count(number+1) == 1){
            count++;
        }
    }
    return count;
}

int main(){
    int length ;
    cin >> length;

    vector<int> array;

    for(int i=0; i<length; i++){
        int temp;
        cin >> temp;
        array.push_back(temp);
    }

    int answer = countElements(array);

    cout << answer << endl;
    return 0;
}