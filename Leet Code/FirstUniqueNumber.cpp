#include<bits/stdc++.h>
using namespace std;

class FirstUnique{

    unordered_map<int,int> count_occur;
    queue<int> q;

public:
    FirstUnique(vector<int>& nums) {
        for(int x: nums) {
            add(x);
        }
    }

    int showFirstUnique() {
        while(!q.empty() && count_occur[q.front()] >= 2) {
            q.pop();
        }
        if(q.empty()) {
            return -1;
        }
        return q.front();
    }

    void add(int value) {
        count_occur[value]++;
        q.push(value);
    }

};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    while(test--) {

        //calling the required method as per the test case

    }
}