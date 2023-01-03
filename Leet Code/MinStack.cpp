/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
*/

#include<bits/stdc++.h>
using namespace std;

class Minstack{
    public:

    // Maintaing the stack of pair where the first stores the value and second stores the current min value;
    // we need pair because if we use the single varible then it will only remeber the latest one
    // once that is removed then we don't have the previous one
    stack<pair<int,int>> s;

    Minstack(){

    }

    void push(int x){
        if(s.empty()){
            s.push({x,x});
        }

        else{
            s.push({x,min(s.top().second,x)});
        }
    }

    void pop(){
        if(!s.empty()){
            s.pop();
        }
    }

    int top(){
        return s.top().first;
    }

    int getmin(){
        return s.top().second;
    }
};