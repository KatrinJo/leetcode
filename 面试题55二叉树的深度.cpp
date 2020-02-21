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
    int maxDepth(TreeNode* root) {
        return traverse(root, 0);
    }

    int traverse(TreeNode* root, int depth) {
        if (root == NULL)
            return depth;
        int d1 = traverse(root->left, depth + 1);
        int d2 = traverse(root->right, depth + 1);
        return max(d1, d2);
    }
};