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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return isSymSub(root->left, root->right);
    }

    bool isSymSub(TreeNode* l, TreeNode* r) {
        if (l == NULL && r == NULL)
            return true;
        if (!(l != NULL && r != NULL))
            return false;
        if (l->val != r->val)
            return false;
        return isSymSub(l->left, r->right) && isSymSub(l->right, r->left);
    }
};