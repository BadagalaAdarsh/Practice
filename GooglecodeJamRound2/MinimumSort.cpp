#include<bits/stdc++.h>
using namespace std;

int n;

void check(){
    int r;
    scanf("%d",&r);
    assert(r==1);
}

void test_case(){
    
    for(int i = 1; i <= n-1; ++i){
        printf("M %d %d\n", i, n);
        fflush(stdout);
        int x;
        scanf("%d",&x);
        if(x != i){
            printf("S %d %d\n", i, x);
            fflush(stdout);
            check();
        }        
    }

    puts("D");
    fflush(stdout);
    check();
}

int main()
{
    int test;
    cin >> test >> n;

    while(test--){
        test_case();
    }
}