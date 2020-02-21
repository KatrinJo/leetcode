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
    int cnt;
    TreeNode* res;
    int kthLargest(TreeNode* root, int k) {
        cnt = 0;
        res = NULL;
        traverse(root, k);
        return res->val;
    }

    void traverse(TreeNode * root, int k) {
        if (root == NULL)
            return;
        if (res != NULL)
            return;
        traverse(root->right, k);
        cnt += 1;
        if (cnt == k) {
            res = root;
            return;
        }
        traverse(root->left, k);
    }
};