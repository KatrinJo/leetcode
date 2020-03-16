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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head; 
        auto tail = head;
        while(tail->next != NULL)
            tail = tail->next;
        
        auto tmp = reve(head, tail);
        return tmp.first;
    }

    pair<ListNode*, ListNode*> reve(ListNode* head, ListNode* tail) {
        if (head == NULL || head == tail)
            return make_pair(head, tail);
        
        auto tmp = reve(head->next, tail);
        tmp.second->next = head;
        head->next = NULL;
        return make_pair(tmp.first, head);
    }

};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* aft, * ret = NULL;
        while(head != NULL) {
            aft = head;
            head = head->next;
            aft->next = ret;
            ret = aft;
        }
        return ret;        
    }
};