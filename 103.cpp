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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<vector<int>> res;
        queue<pair<TreeNode*, int>> myque;
        TreeNode * tmp;
        myque.push(make_pair(root, 0));
        while(!myque.empty()) {
            auto t = myque.front();
            myque.pop();
            tmp = t.first;
            if (res.size() <= t.second)
                res.push_back(vector<int>{});
            res[t.second].push_back(tmp->val);
            if (tmp->left != NULL)
                myque.push(make_pair(tmp->left, t.second + 1));
            if (tmp->right != NULL)
                myque.push(make_pair(tmp->right, t.second + 1));
            
        }
        for (int i = 0; i < res.size(); ++i) 
            if (i % 2) 
                reverse(res[i].begin(), res[i].end());
        return res;
    }
};