#include<bits/stdc++.h>
using namespace std;

int rangeBitwiseAndUsingRecursion(int left, int right){
    
    if (left == right){
        return left;
    }
    return rangeBitwiseAndUsingRecursion(left>>1, right >> 1) << 1;
}

int rangeBitwiseAndUsingIteration(int left, int right){
    int answer = 0;
    while (left < right){
        left >> 1;
        right >> 1;
        answer++;
    }
    answer = right << answer;
    return answer;
}

int rangeBitwiseAndErrochtoVersion(int left, int right){
    int answer = 0;
    for(int bit = 30 ; bit >= 0; bit--){ // even though int is 32 bit we start at 30 because index is from 0
    // so range of bits is 0 to 31, as it is signed number 31st bit is from sign so 0 to 30
        if ((left & (1 << bit) != (right & (1 << bit))){
            break;
        }
        else{
            answer |= (left & (1 << bit));
        }
    }
    return answer;
}

int main(){
    int test;
    cin >> test;

    while(test--){
        int left, right;
        cin >> left >> right ;

        cout << rangeBitwiseAndUsingRecursion(left, right) << endl;
        cout << rangeBitwiseAndUsingIteration(left, right) << endl;
        cout << rangeBitwiseAndErrochtoVersion(left, right) << endl;

        // all the three logics are same checking for common bits from MSB side
        // then filling rest with 0
        // example left = 5 (101) and right = 7(111)
        // common bit from right (MSB) is only one and we get to see that after 2 right shifts
        // 1 is left shifted two time (100) which is 4 final answer
    }
}