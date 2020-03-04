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
private:
    int num;
    int cnt;
public:
    int kthSmallest(TreeNode* root, int k) {
        num = 0;
        cnt = 0;
        search(root, k);
        return num;
    }

    void search(TreeNode* root, int k) {
        if (cnt == -1) return;
        if (root->left != NULL) 
            search(root->left, k);
        if (cnt == -1) return;
        ++cnt;
        if (cnt == k) {
            num = root->val;
            cnt = -1;
            return;
        }
        if (root->right != NULL)
            search(root->right, k);      
    }
};