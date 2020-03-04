/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    int closestValue(TreeNode * root, double target) {
        // write your code here
        int res = root->val;
        double sub = target - root->val;
        closest(root, target, res);
        return res;
    }
    
    void closest(TreeNode * root, double target, int & res) {
        if (abs(target - root->val) < abs(target - res))
            res = root->val;
        
        if (root->left != NULL && root->val > target)
            closest(root->left, target, res);
        if (root->right != NULL && root->val < target)
            closest(root->right, target, res);
    }
};