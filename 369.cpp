/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: the first Node
     * @return: the answer after plus one
     */
    ListNode * plusOne(ListNode * head) {
        // Write your code here
        if (plus(head)) {
            ListNode * newhead = new ListNode(1);
            newhead->next = head;
            head = newhead;
        }
        return head;
    }
    
    bool plus(ListNode * h) {
        bool res = false;
        if (h->next == NULL)
            res = true;
        else
            res = plus(h->next);
        
        if (res) {
            if (h->val == 9) {
                h->val = 0;
                return true;
            }
            ++h->val;
        }
        return false;
    }
};