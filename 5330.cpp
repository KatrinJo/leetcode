// dp
// 需要学习的思想：打表记录中间过程。

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
    vector<long long int> res;

    long long int sum(TreeNode * root) {
        long long s = 0;
        if (root != NULL)
            s = root->val + sum(root->left) + sum(root->right);
        res.push_back(s);
        return s;        
    }
    int maxProduct(TreeNode* root) {
        long long int ret = 0, tmp;
        long long int allSum = sum(root);
        for (auto & x : res) {
            ret = max(ret, x * (allSum - x));
        }
        return ret % (1000000007);
    }
};
