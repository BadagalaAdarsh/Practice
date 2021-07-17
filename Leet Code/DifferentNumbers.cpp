/*
You are given N <= 10^7 numbers, each between 0 and 10^9. How many different values apppear in the 
sequence
*/

#include<bits/stdc++.h>
using namespace std;

int first_implementaion(vector<int>& array, int size){

    bitset<1000000001> visited;
    int answer = 0;

    for(int i = 0; i < size; i++){
        int x = array[i];

        if(!visited[x] == true){
            visited[x] = true;
            answer++;
        }
    }

    return answer;
}

int second_implementation(vector<int>& array, int size){

    bitset<1000000001> visited;
    
    for(int i = 0; i < size; i++){
        int x = array[i];
        visited[x] = true;
    }

    return visited.count();
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

        cout << first_implementaion(array, n) << endl;
        cout << second_implementation(array, n) << endl;
    }
}