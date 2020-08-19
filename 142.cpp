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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) 
            return nullptr;
        ListNode * slow = head, * fast = head;
        while(fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == nullptr)
                break;
            if (slow == fast) {
                fast = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};