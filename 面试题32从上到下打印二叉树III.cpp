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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<vector<int>> res;
        int currdepth = -1;

        vector<pair<TreeNode*, int>> myvec;

        TreeNode* curr;
        myvec.push_back(make_pair(root, 0));
        int l = 0, r = 1, depth = 0;
        while(l < r) {
            auto ele = myvec[l];
            ++l;
            curr = ele.first;
            depth = ele.second;

            if (depth > currdepth) {
                res.push_back(vector<int>{curr->val});
                currdepth = depth;
            }
            else {
                res[depth].push_back(curr->val);
            }

            if (curr->left != NULL) {
                myvec.push_back(make_pair(curr->left, depth+1));
                ++r;
            }
            if (curr->right != NULL) {
                myvec.push_back(make_pair(curr->right, depth+1));
                ++r;
            }
        }
        int n = res.size();
        for (int i = 1; i < n; i+=2) {
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
};