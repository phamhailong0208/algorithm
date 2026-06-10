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
ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;

    // Bước 1: phát hiện vòng
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            // Bước 2: tìm node bắt đầu vòng
            ListNode* ptr1 = head;
            ListNode* ptr2 = slow;
            while (ptr1 != ptr2) {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            return ptr1;
        }
    }
    return nullptr;
}
};