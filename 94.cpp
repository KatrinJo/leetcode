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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL)
            return {};
        if (root->left == NULL && root->right == NULL)
            return vector<int>{root->val};
        vector<int> res;
        auto r = inorderTraversal(root->left);
        res.insert(res.end(), r.begin(), r.end());
        res.push_back(root->val);
        auto r2 = inorderTraversal(root->right);
        res.insert(res.end(), r2.begin(), r2.end());
        return res;
        
    }
};