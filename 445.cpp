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
    int llen(ListNode* l) {
        if (l == NULL) return 0;
        return 1 + llen(l->next);
    }

    bool add(ListNode* l1, ListNode* l2, int len1, int len2) {
        if (l1 == NULL || l2 == NULL)
            return false;
        bool flag = false;
        if (len1 > len2) {
            flag = add(l1->next, l2, len1 - 1, len2);
            l1->val += flag;
            if (l1->val >= 10) {
                l1->val -= 10;
                flag = true;
            }
            else 
                flag = false;
        }            
        else if (len1 == len2) {
            flag = add(l1->next, l2->next, len1 - 1, len2 - 1);
            l1->val += l2->val + flag;
            if (l1->val >= 10) {
                l1->val -= 10;
                flag = true;
            }
            else 
                flag = false;
        }
        return flag;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        else if (l2 == NULL) return l1;
        int len1 = llen(l1), len2 = llen(l2);
        if (len1 < len2) return addTwoNumbers(l2, l1);
        bool flag = add(l1, l2, len1, len2);
        if (flag) {
            ListNode * head = new ListNode(1);
            head->next = l1;
            l1 = head;
        }
        return l1;        
    }
};






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
    pair<ListNode*, ListNode* > reverse(ListNode* l) {
        if (l == NULL || l->next == NULL) return make_pair(l, l);
        auto tmp = reverse(l->next);
        tmp.second->next = l;
        l->next = NULL;
        return make_pair(tmp.first, l);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        else if (l2 == NULL) return l1;
        auto tmp1 = reverse(l1);
        auto tmp2 = reverse(l2);
        ListNode* curr1 = tmp1.first, * curr2 = tmp2.first, * tmp;
        bool flag = false;
        while(curr1 != NULL && curr2 != NULL) {
            curr1->val += curr2->val + flag;
            if (curr1->val >= 10) {
                curr1->val -= 10;
                flag = true;
            }
            else
                flag = false;
            if (curr1->next == NULL && curr2->next == NULL && flag) {
                curr1->next = new ListNode(1);
                flag = false;
            }
            if (curr1->next == NULL) {
                curr1->next = curr2->next;
                curr2->next = NULL;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        while(curr1 != NULL) {
            curr1->val += flag;
            if (curr1->val >= 10) {
                curr1->val -= 10;
                flag = true;
            }
            else
                flag = false;
            if (curr1->next == NULL && flag) {
                curr1->next = new ListNode(1);
                flag = false;
            }
            curr1 = curr1->next;
        }
        tmp1 = reverse(tmp1.first);
        return tmp1.first;
    }
};