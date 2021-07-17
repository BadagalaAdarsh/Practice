#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;

    while(test--){
        int n;
        cin >> n;

        vector<int> array(n);

        for(int i=0; i<n; i++){
            cin >> array[i];
        }

        vector<int> answer(n);

        int i=0;
        int index = 0;
        while(index<n){
            answer[index] = array[i];
            index++;
            answer[index] = array[n-i-1];
            i++;
            index++;
        }

        for (auto numbers: answer){
            cout << numbers << " " ;
        }
    }

    return 0;
}