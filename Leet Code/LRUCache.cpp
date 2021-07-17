#include<bits/stdc++.h>
using namespace std;

class LRUCache {

private:
    unordered_map<int,int> value;
    queue<int> accessed;
    unordered_map<int,int> cnt_in_queue;
    int capacity;

    void add_to_queue(int key) {
        accessed.push(key);
        cnt_in_queue[key]++;
    }

public:
    LRUCache(int given_capacity) {
        capacity = given_capacity;
    }

    int get(int key) {
        auto it = value.find(key);

        if (it == value.end()){
            return -1;
        }

        add_to_queue(key);
        return it->second; // same as value[key] but it is bit slow as it needs to do hash function
    }

    void put(int key, int v) {

        if((int)value.size() < capacity) {
            value[key] = v;
            add_to_queue(key);
            return;
        }

        auto it = value.find(key);
        if(it != value.end()) {
            it->second = v;
            add_to_queue(key);
            return;
        }

        while(true) {
            int candidate = accessed.front();
            accessed.pop();

            if(--cnt_in_queue[candidate] == 0){
                cnt_in_queue.erase(candidate);
                value.erase(candidate);
                break;
            }            
        }

        value[key] = v;
        add_to_queue(key);
    }

};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    while (test--) {
        // calling the LRU related functions as needed based on the test cases;
    }
}