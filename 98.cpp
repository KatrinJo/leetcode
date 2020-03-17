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
    bool isvalid(TreeNode* root, long long int min, long long int max) {
        if (root == NULL)
            return true;
        if (root->val <= min || root->val >= max)
            return false;
        return (isvalid(root->left, min, root->val) && isvalid(root->right, root->val, max));
    }
    bool isValidBST(TreeNode* root) {
        return isvalid(root, ((long long int)INT_MIN) - 1, ((long long int)INT_MAX) + 1);
    }
};