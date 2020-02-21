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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* res = new ListNode(-1), *tmp, *LNnext;
        tmp = res;
        auto cmp = [](const ListNode* a,const ListNode* b) {
            if (b == NULL)
                return true;
            if (a == NULL)
                return false;
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp) > myque(cmp);
        for (int i = 0; i < n; ++i) {
            if (lists[i] != NULL) {
                myque.push(lists[i]);
            }
        }

        while(!myque.empty()) {
            auto x =  myque.top();
            myque.pop();
            tmp->next = x;
            tmp = tmp->next;

            if (x->next != NULL) {
                myque.push(x->next);
            }
        }
        return res->next;
    }
};


