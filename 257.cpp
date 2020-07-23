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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL)
            return {};
        if (root->left == NULL && root->right == NULL) {
            return vector<string> {to_string(root->val)};
        }
        vector<string> res = binaryTreePaths(root->left);
        vector<string> rightres = binaryTreePaths(root->right);
        for_each(rightres.begin(), rightres.end(), [&](string s){
            res.push_back(move(s));
        });
        string curr = to_string(root->val);
        for (auto & str : res)
            str = curr + "->" + str;
        return res;
    }
};