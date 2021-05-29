#include<bits/stdc++.h>
using namespace std;

int subArraySum(vector<int>& array, int k) {
    // sub array sum of array[L ...... R] = prefix[R] - prefix[L-1]
    int n = array.size();
    int answer = 0;
    int pref = 0;
    unordered_map<int, int> countPref;
    countPref[pref]++;

    for(int R = 0; R < n; R++) {
        pref += array[R];
        int need = pref - k;
        answer += countPref[need];
        countPref[pref]++;
    }
    return answer;
}

int main(){
    int test;
    cin >> test;

    while(test--) {
        int n;
        cin >> n;
        vector<int> array(n);

        for(int i = 0; i < n; i++) {
            cin >> array[i] ;
        }
        int k;
        cin >> k;

        cout << subArraySum(array, k) << endl;
    }
}