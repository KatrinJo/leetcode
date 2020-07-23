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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* curr = head, * tmp;
        while(curr != NULL) {
            tmp = curr->next;
            while(tmp != NULL && curr->val == tmp->val) {
                curr->next = tmp->next;
                delete tmp;
                tmp = curr->next;
            }
            curr = curr->next;
        }
        return head;
    }
};