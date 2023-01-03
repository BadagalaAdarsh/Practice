#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<pair<int,int>> array;

    for(int i =0; i < n ; i++){
        int one,two;
        cin >> one >> two ;
        array.push_back(make_pair(one,two));
    }

    int chris = 0, mishra = 0;

    for(int i = 0; i < n ; i++){
        
        if (array[i].first > array[i].second){
            chris++;
        }
        else if (array[i].second > array[i].first){
            mishra++;
        }
    }

    if (chris > mishra){
        cout << "Mishka" << endl;
    }

    else if (mishra > chris){
        cout << "Chris" << endl;
    }

    else if (mishra == chris){
        cout<<"Friendship is magic!^^"<<endl;
    }

    return 0;
}