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
     * @param k: the given k
     * @return: k values in the BST that are closest to the target
     */
    vector<int> closestKValues(TreeNode * root, double target, int k) {
        // write your code here
        if (root == NULL) return {};
        priority_queue<pair<double, int>> pq;
        cal(pq, root, target, k);
        vector<int> res;
        while(!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            res.push_back(x.second);
        }
        return res;
    }
    
    void cal(priority_queue<pair<double, int>> & pq, TreeNode * root, double target, int k) {
        while(pq.size() > k)
            pq.pop();
        if (pq.size() == k) {
            auto tmp = pq.top();
            if (abs(target - root->val) < tmp.first) {
                pq.pop();
                pq.push(make_pair(abs(target - root->val), root->val));
            }
        }
        else 
            pq.push(make_pair(abs(target - root->val), root->val));
        
        if (root->left != NULL)
            cal(pq, root->left, target, k);
        if (root->right != NULL)
            cal(pq, root->right, target, k);
    }
};