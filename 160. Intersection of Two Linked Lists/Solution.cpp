/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
int getlength(ListNode *head){
    int len = 0;
    while(head!=NULL){
        len++;
        head = head->next;
    }
    return len;
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }
        int lenA = getlength(headA);
        int lenB = getlength(headB);
        while(lenA > lenB){
            headA = headA->next;
            lenA--;
        }
        while(lenB>lenA){
            headB = headB->next;
            lenB--;
        }
            // Traverse both lists simultaneously
    while (headA != NULL && headB != NULL) {
        if (headA == headB) {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }

    return NULL;

    }
};