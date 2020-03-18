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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode * slow = head, * fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        slow = sortList(head);
        fast = sortList(fast);
        ListNode * curr;
        if (slow->val <= fast->val) {
            head = slow;
            slow = slow->next;
        }
        else {
            head = fast;
            fast = fast->next;
        }
        curr = head;
        while(slow && fast) {
            if (slow->val <= fast->val) {
                curr->next = slow;
                slow = slow->next;
            }
            else {
                curr->next = fast;
                fast = fast->next;
            }
            curr = curr->next;
        }
        while(slow) {
            curr->next = slow;
            slow = slow->next;
            curr = curr->next;
        }
        while(fast) {
            curr->next = fast;
            fast = fast->next;
            curr = curr->next;
        }
        return head;
    }
};