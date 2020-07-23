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
    TreeNode * build(vector<int> & nums, int l, int r) {
        TreeNode * root;
        if (l == r)
            root = new TreeNode(nums[l]);
        else if (l == r - 1) {
            root = new TreeNode(nums[r]);
            root->left = new TreeNode(nums[l]);
        }
        else {
            int m = (l + r) >> 1;
            root = new TreeNode(nums[m]);
            root->left = build(nums, l, m - 1);
            root->right = build(nums, m + 1, r);
        }
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
            return NULL;
        return build(nums, 0, nums.size() - 1);
    }
};