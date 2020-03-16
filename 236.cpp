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
    pair<bool, bool> dfs(TreeNode * root, TreeNode * & res, TreeNode* p, TreeNode* q) {
        if (res != NULL)
            return make_pair(false, false);
        if (root == NULL)
            return make_pair(false, false);

        auto res1 = dfs(root->left, res, p, q);

        if (res != NULL)
            return make_pair(false, false);

        auto res2 = dfs(root->right, res, p, q);

        // cout << root->val << " " << res1.first << " " << res1.second << " " << res2.first << " " << res2.second << endl;
        if (res != NULL)
            return make_pair(false, false);

        res1.first = (root->val == p->val) || res1.first || res2.first;
        res1.second = (root->val == q->val) || res1.second || res2.second;
        // cout << root->val << " " << res1.first << " " << res1.second << endl;

        if (res1.first && res1.second) {
            res = root;
            return make_pair(false, false);
        }
        return res1;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        TreeNode* res = NULL;
        dfs(root, res, p, q);
        return res;
    }
};