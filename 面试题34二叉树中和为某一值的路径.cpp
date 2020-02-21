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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return {};
        
        vector<vector<int>> res;
        vector<int> med;
        printPath(res, med, root, sum);
        return res;
    }

    void printPath(vector<vector<int>> & res, vector<int> & med, TreeNode* root, int sum) {
        med.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (sum == root->val)
                res.push_back(med);
            med.pop_back(); 
            return;
        }
        if (root->left != NULL)
            printPath(res, med, root->left, sum-root->val);
        if (root->right != NULL)
            printPath(res, med, root->right, sum-root->val);
        med.pop_back();        
    }
};