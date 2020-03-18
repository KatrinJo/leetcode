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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n)
            return head;
        ListNode * bef = head, * curr = head->next, * tmp, * tail;
        for (int i = 2; i < m; ++i) {
            bef = bef->next;
            curr = curr->next;
        }
        if (m == 1) {
            tail = head;
            tmp = head;
        }
        else {
            tail = curr;
            tmp = curr;
            curr = curr->next;
        }
        for (int i = m; i < n; ++i) {
            tail->next = curr->next;
            curr->next = tmp;
            tmp = curr;
            curr = tail->next;
        }

        if (m == 1) 
            head = tmp;
        else
            bef->next = tmp;
        return head;        
    }
};