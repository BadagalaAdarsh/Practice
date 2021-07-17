#include<bits/stdc++.h>
using namespace std;


// below function is to generator a random number between a range of numbers
int rand(int a, int b) {
    return a + rand() % ( b - a + 1 );
}

// while running this program we need to give the command line argument
// example
    // ./a.out 200 where 200 is argv[1] which sets the seed for the 
    // randomness
int main(int argc, char* argv[] ) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int

    // below logic is to generate a array of distinct numbers of size n
    //int n = rand(2, 1000);
    int n = 100;
    printf("%d\n", n);

    set<int> used; // as we need to generate distinct numbers i am using 
				   // set here
    for(int i = 0; i < n; ++i ) {
        int x;
        do {
            x = rand(1, 100);
        } while( used.count(x));

        printf("%d ", x);
        used.insert(x);
    }

    puts("");
}
