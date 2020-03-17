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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)
            return head;
        ListNode * curr, * follow, * ahead = new ListNode(-1), * tmp;
        ListNode * newhead;
        ahead->next = head;
        follow = ahead;
        bool flag = false;
        while(true) {
            curr = follow;
            for (int i = 0; i < k; ++i) {
                if (follow == NULL) {
                    flag = true;
                    break;
                }
                follow = follow->next;
            }
            if (flag || follow == NULL)
                break;
            newhead = curr->next;
            follow = newhead->next;
            for (int i = 1; i < k; ++i) {
                tmp = follow;
                follow = follow->next;
                tmp -> next = newhead;
                newhead = tmp;
            }
            curr->next = newhead;
            for (int i = 0; i < k; ++i)
                curr = curr->next;
            curr->next = follow;
            follow = curr;
        }
        return ahead->next;
    }
};