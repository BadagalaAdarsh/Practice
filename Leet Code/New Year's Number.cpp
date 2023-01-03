#include<bits/stdc++.h>
using namespace std;

int main(){

    int test;
    cin >> test;

    while(test--){

            int year;
            cin >> year;

            if (year < 2020){
                cout << "NO" << endl;
            }

            else if (year%2020 == 0 || year%2021 == 0){
                cout << "YES" << endl;
            }

            else{
                int temp = year%2020;
                int temp2 = year/2020;

                //cout << temp << " " << temp2 << endl;

                if (temp2 -1 < temp){
                    cout << "NO" << endl;
                }
                else{
                    cout << "YES" << endl;
                }
            }

    }

    return 0;
}