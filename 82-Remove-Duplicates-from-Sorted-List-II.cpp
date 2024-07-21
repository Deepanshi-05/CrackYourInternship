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
ListNode* deleteDuplicates(ListNode* head) {

     if (head == NULL) {
        return head;
    }

    // Dummy node to handle edge cases easily
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;  // Last node before the sequence of duplicates

    while (head != NULL) {
        // Check if the current node is a start of duplicates
        if (head->next != NULL && head->val == head->next->val) {
            // Move head to the end of the duplicates
            while (head->next != NULL && head->val == head->next->val) {
                head = head->next;
            }
            // Skip all duplicates
            prev->next = head->next;
        } else {
            // Move prev forward only when no duplicates
            prev = prev->next;
        }
        // Move head forward
        head = head->next;
    }

    return dummy.next;
}
};