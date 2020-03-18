/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)
            return NULL;
        if (head->next == NULL) 
            return new TreeNode(head->val);
        if (head->next->next == NULL) {
            TreeNode * left = new TreeNode(head->val);
            head = head->next;
            TreeNode * root = new TreeNode(head->val);
            root->left = left;
            return root;
        }
        ListNode * slow = head, * fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = head;
        while(fast->next && fast->next != slow) 
            fast = fast->next;
        fast->next = NULL;
        fast = slow->next;
        slow->next = NULL;

        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(fast);
        return root;
    }
};