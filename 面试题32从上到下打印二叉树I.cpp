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
    vector<int> levelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<int> res;
        vector<TreeNode*> myvec;
        TreeNode* curr;
        myvec.push_back(root);
        int l=0, r=1;
        while(l < r) {
            curr = myvec[l];
            ++l;
            res.push_back(curr->val);
            if (curr->left != NULL) {
                myvec.push_back(curr->left);
                ++r;
            }
            if (curr->right != NULL) {
                myvec.push_back(curr->right);
                ++r;
            }
        }
        return res;
    }
};