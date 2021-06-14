#include<bits/stdc++.h>
using namespace std;

long long gcd(long long int a, long long int b){
    if (b==0){
        return a;
    }
    return gcd(b, a%b);
}

long long lcm(long long a, long long b){
    return (a/gcd(a,b)) * b;
}

int main()
{
    int test;
    cin >> test;

    while(test--){
        long long a,b;
        cin >> a >> b ;

        long long answer1 = -1, answer2 = -1;
        long long temp;

        for(long long i=a; i<=b ; i++){
            for(long long j=a; j<=b; j++){
                if (i==j){
                    continue;
                }

                temp = lcm(i,j);

                if (temp >= a && temp <= b){
                    answer1 = i;
                    answer2 = j;
                    break;
                }
            }
            if(temp > b){
                break;
            }

            if (answer1 != -1){
                break;
            }
        }

        cout << answer1 << " " << answer2 << endl;
    }

    return 0;
}