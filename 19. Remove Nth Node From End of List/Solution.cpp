/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy  = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        for(int i = 0; i<n ; i++){
            if(fast!=NULL){
                fast = fast->next;
            }
            else{
                return head;
            }
        }
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};