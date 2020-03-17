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

    ListNode * get(ListNode *headA, ListNode *headB, int lenA, int lenB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        if (headA == headB)
            return headA;
        if (lenA > lenB)
            return get(headA->next, headB, lenA - 1, lenB);
        return get(headA->next, headB->next, lenA - 1, lenB - 1);
    } 
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tmp;
        tmp = headA;
        int lenA = 0, lenB = 0;
        while(tmp != NULL) {
            tmp = tmp->next;
            ++lenA;
        }
        tmp = headB;
        while(tmp != NULL) {
            tmp = tmp->next;
            ++lenB;
        }
        if (lenA >= lenB) 
            return get(headA, headB, lenA, lenB);
        else
            return get(headB, headA, lenB, lenA);        
    }
};