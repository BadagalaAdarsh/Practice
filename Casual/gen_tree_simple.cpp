#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int rand(int a, int b) {
    return a + rand() % ( b + a - 1);
}

int main(int argc, char* argv[] ) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    srand(atoi(argv[1]));

    int n = rand(2, 20);
    printf("%d\n", n);

    for(int i = 2; i <= n; i++) {
        printf("%d %d\n", rand(1, i - 1), i); 
        // printf("%d %d\n", 1, i) is used to get the tree in the shape of the star
        // printf("%d %d\n", i/2, i) can be used to generate the binary tree
    }

    // creates tree in a such a way that say 1 is root 2 is child
    // next 3 is generated then its parent is randomly generated either 2 or 1
    // similarily for 4 parent can be 1 , 2 or 3
}
