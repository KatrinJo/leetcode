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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode * ret = head->next, * bef = head, * tmp;
        head->next = ret->next;
        ret->next = head;
        while(true) {
            if (bef->next == NULL || bef->next->next == NULL)
                break;
            tmp = bef->next;
            bef->next = tmp->next;
            tmp->next = bef->next->next;
            bef->next->next = tmp;
            bef = tmp;
        }
        return ret;
    }
};