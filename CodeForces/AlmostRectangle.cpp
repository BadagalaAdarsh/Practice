#include<bits/stdc++.h>
using namespace std;

int main(){

    int test;
    cin >> test;

    while (test--){

        int n;
        cin >> n;
        vector<string> str(n);
        vector<pair<int,int>> point;

        for(int i=0; i<n; i++){
            cin >> str[i];
            for(int j=0; j<n; j++){

                if (str[i][j] == '*'){
                    point.push_back({i,j});
                }
            }
        }

        point.push_back(point[0]);
        point.push_back(point[1]);

        if (point[0].first == point[1].first){
            point[2].first = (point[2].first + 1) % n;
            point[3].first = (point[3].first + 1) % n;
        }

        else if (point[0].second == point[1].second){
            point[2].second = (point[2].second + 1) % n;
            point[3].second = (point[3].second + 1) % n;
        }

        else{
            swap(point[2].first, point[3].first);
        }


        str[point[2].first][point[2].second] = '*';
        str[point[3].first][point[3].second] = '*';

        for(int i=0; i<n; i++){
            cout << str[i] << endl;
        }
    }

    return 0;
}