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

    ListNode * reverse(ListNode * head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode * root = head, * curr = head->next;
        while(curr) {
            head->next = curr->next;
            curr->next = root;
            root = curr;
            curr = head->next;
        }
        return root;
    }
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return;

        ListNode * slow = head, * fast = head;
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        slow = head;
        fast = reverse(fast);
        ListNode* curr;
        while(fast) {
            curr = fast->next;
            fast->next = slow->next;
            slow->next = fast;
            slow = fast->next;
            fast = curr;
        }
    }
};