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
ListNode* getMiddle(ListNode* head) {
    if (head == nullptr) return head;
    
    ListNode* slow = head;
    ListNode* fast = head->next;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}
ListNode* merge(ListNode* left, ListNode* right) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    
    while (left != nullptr && right != nullptr) {
        if (left->val < right->val) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }
    
    tail->next = (left != nullptr) ? left : right;
    
    return dummy.next;
}

    ListNode* sortList(ListNode* head) {
         if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    ListNode* middle = getMiddle(head);
    ListNode* nextOfMiddle = middle->next;
    
    middle->next = nullptr;
    
    ListNode* left = sortList(head);
    ListNode* right = sortList(nextOfMiddle);
    
    ListNode* sortedList = merge(left, right);
    
    return sortedList;
    }
};