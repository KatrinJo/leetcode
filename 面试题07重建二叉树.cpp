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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (n == 0)
            return NULL;
        return buildSubTree(preorder, inorder, 0, n-1, 0, n-1);
    }
    TreeNode* buildSubTree(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        if (pl > pr)
            return NULL;
        int val = preorder[pl];
        TreeNode * root = new TreeNode(val);
        if (pl == pr)
            return root;
        int k;
        for (k = il; k <= ir; ++k)
            if (inorder[k] == val)
                break;    
        root->left = buildSubTree(preorder, inorder, pl+1, k-il+pl, il, k);
        root->right = buildSubTree(preorder, inorder, k-il+pl+1, pr, k+1, ir);
        return root;   
    }

};