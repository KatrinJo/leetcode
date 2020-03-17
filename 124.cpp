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
    void search(TreeNode * root, int sum, int & maxval) {
        if (root == NULL)
            return;
        maxval = max(maxval, sum + root->val);
        search(root->left, sum + root->val, maxval);
        search(root->right, sum + root->val, maxval);
    }
    int maxPathSum(TreeNode* root) {
        if (root->left == NULL && root->right == NULL)
            return root->val;
        int maxv = root->val;
        int lmax = 0, rmax = 0;
        search(root->left, 0, lmax);
        search(root->right, 0, rmax);
        maxv = max(maxv, max(max(lmax, rmax), lmax + rmax) + root->val);
        if (root->left != NULL) {
            maxv = max(maxv, maxPathSum(root->left));
        }
        if (root->right != NULL) {
            maxv = max(maxv, maxPathSum(root->right));
        }
        return maxv;
    }
};