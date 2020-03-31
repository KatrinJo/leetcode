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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;
        if (root->left == NULL && root->right == NULL)
            return sum == root->val;
        bool res = false;
        sum -= root->val;
        if (root->left != NULL)
            res = hasPathSum(root->left, sum);
        if (root->right != NULL)
            res = res || hasPathSum(root->right, sum);
        return res;
    }
};