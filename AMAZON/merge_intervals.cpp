/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    vector<vector<int>> res;


    // sorting the 2d array based on the first number which uses lamda function
    sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
        return a[0] < b[0];
    });

    res.emplace_back(intervals[0]);

    // traverse the intervals vector and add to result based on the overlapping condition

    for(int i =1 ; i < (int)intervals.size(); i++){
        
        // if first number of next interval is smaller or equal to the last number of the previous interval
        if(intervals[i][0] <= res.back()[1]){
            // current last number will the max of current last and next last number
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        }
        else{
            // else directly add the next interval to the result
            res.emplace_back(intervals[i]);
        }
    }
    // return the result
    return res;
}



int main() {

    int n;
    cin >> n;

    vector<vector<int>> intervals(n);

    for(int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<vector<int>> answer = mergeIntervals(intervals);

    // print the final answer

    for(int i = 0; i < (int)answer.size(); i++) {
        cout << answer[i][0] << " " << answer[i][1] << endl;
    }
}