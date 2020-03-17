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

    bool backtracking(ListNode* left, ListNode* & right, ListNode* med) {
        if (left == med) {
            if (left->val == right->val) {
                right = right->next;
                return true;
            }
            else
                return false;
        }
        if (!backtracking(left->next, right, med))
            return false;
        if (left->val == right->val) {
            right = right->next;
            return true;
        }   
        return false;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL)
            return true;
        ListNode * slow = head, * fast = head;
        while(true) {
            if (fast->next == NULL || fast->next->next == NULL)
                break;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast->next == NULL) 
            return backtracking(head, slow, slow);
        return backtracking(head, slow->next, slow);
    }
};