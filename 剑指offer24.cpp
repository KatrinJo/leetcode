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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode * tail = head, * curr = head->next;
        while(curr != nullptr) {
            tail->next = curr->next;
            curr->next = head;
            head = curr;
            curr = tail->next;
        }
        return head;
    }
};