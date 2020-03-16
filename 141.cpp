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
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return false;
        ListNode * onestep = head, * twostep = head;
        while(true) {
            onestep = onestep->next;
            if (twostep->next == NULL || twostep->next->next == NULL)
                break;
            twostep = twostep->next->next;
            if (onestep == twostep)
                return true;
        }
        return false;
    }
};