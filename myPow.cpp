#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n){
    double answer = 0;
    bool flag = false;
    
    if (n == 0){
        return 1;
    }

    if( n < 0 ){
        flag = true;
        n = abs(n);
    }

    while( n > 0 ){
        if (n%2 == 1){
            answer *= x;
        }
        x *= x;
        n /= 2;
    }

    if (flag){
        return 1/answer;
    }
    return answer;
}

int main(){
    int test;
    cin >> test;

    while(test--){
        double x;
        int n;

        cin >> x >> n ;
        cout << myPow(x, n) << endl;
    }
}