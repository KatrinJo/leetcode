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
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL)
            return {};
        queue<pair<TreeNode*, int>> myque;
        myque.push({root, 0});
        vector<int> res{root->val};
        int s = 1;
        while(!myque.empty()) {
            auto tmp = myque.front();
            auto ptr = tmp.first;
            myque.pop();
            if (tmp.second == s) {
                res.push_back(ptr->val);
                ++s;
            }
            if (ptr->right != NULL) 
                myque.push({ptr->right, tmp.second + 1});
            if (ptr->left != NULL)
                myque.push({ptr->left, tmp.second + 1});
        }
        return res;
    }
};