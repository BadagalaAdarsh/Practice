/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
*/

#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0) , next(nullptr)  {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode *head = NULL, *prev = NULL; // we can also do as ListNode * head = 0;
    int carry = 0;

    while( l1 || l2 ) {
        int v1 = l1 ? l1 -> val: 0;
        int v2 = l2 ? l2 -> val: 0;

        int tmp = v1 + v2 + carry;
        carry = tmp / 10;
        int val = tmp % 10;
        ListNode* cur = new ListNode(val);

        if (!head) head = cur; // this condition is true only for once when head is null or 0;
        if (prev) prev -> next = cur;
        prev = cur;

        l1 = l1 ? l1 -> next: NULL;
        l2 = l2 ? l2 -> next: NULL;
    }

    if (carry > 0) {
        ListNode *l = new ListNode(carry);
        prev->next = l;
    }

    return head;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;

    while(test--) {
        cout << "no of digits in l1" << endl;
        int n;
        ListNode* head1 = NULL, *prev1 = NULL;

        while(n--) {
            int val;
            cin >> val;

            ListNode* curr = new ListNode(val);
            if(!head1) head1 = curr;
            if(prev1) prev1 -> next = curr;
            prev1 = curr;
        }

        cout << "no of digits in l2" << endl;
        cin >> n;

        ListNode* head2 = NULL, *prev2 = NULL;

        while(n--) {
            int val;
            cin >> val;

            ListNode* curr = new ListNode(val);
            if(!head2) head2 = curr;
            if (prev2) prev2 -> next = curr;
            prev2 = curr;
        }

        // calling the required funtion
    }
}