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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (B == NULL)
            return false;
        return judge(A, B);
    }
    bool judge(TreeNode* A, TreeNode* B) {
        if (A == NULL) 
            return false;
        if (traverse(A, B))
            return true;
        if (judge(A->left, B))
            return true;
        return judge(A->right, B);
    }
    bool traverse(TreeNode* A, TreeNode* B) {
        if (B == NULL)
            return true;
        if (A == NULL)
            return false;
        if (A->val != B->val)
            return false;
        return traverse(A->left, B->left) && traverse(A->right, B->right);
    }
};