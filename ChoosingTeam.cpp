#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,k;

    cin >> n >> k ;

    vector<int> array;

    for(int i = 0 ; i < n ; i++){

        int temp;
        cin >> temp;
        array.push_back(temp);
    }

    int count = 0;

    for (int i = 0 ; i < n; i++){

        if (5 - array[i] >= k){
            count++;
        }
    }

    cout<<count/3<<endl;

    return 0;
}
