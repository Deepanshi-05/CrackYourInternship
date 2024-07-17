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
ListNode* reverse(ListNode* head){
     // Initialize current, previous and next pointers
       ListNode* current = head;
       ListNode *prev = NULL;
       ListNode *next = NULL;

        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        return prev;
}

    int getDecimalValue(ListNode* head) {
        ListNode* temp = reverse(head);
        long int base = 1;
        int sum = 0;
        while(temp != NULL){
            sum += temp->val*base;
            base = base*2;
            temp = temp->next;
        }
            return sum;
            }
};