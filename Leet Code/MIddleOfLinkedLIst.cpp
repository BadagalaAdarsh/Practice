/*
assuming all the methods regarding linked list are already available
*/

ListNode* middleNode(ListNode* head){

    ListNode* one = head;
    ListNode* two = head;

    while(two != NULL){
        two = two->next;
        if(two == NULL){
            return one;
        }
        one = one->next;
        two = two->next;
    }

    return one;
}