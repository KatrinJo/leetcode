/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    TreeNode* r;
    vector<TreeNode*> path;
    BSTIterator(TreeNode* root) {
        r = root;
        while(root!= NULL) {
            path.push_back(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        int num = path.back()->val;
        TreeNode* tmp = path.back();
        path.pop_back();

		if (tmp->right == NULL) {
			while (path.size() > 0 && path.back() -> right == tmp) {
				tmp = path.back();
				path.pop_back();
			}
		}
		else {
            path.push_back(tmp);
            tmp = tmp->right;
            path.push_back(tmp);
            while(tmp->left != NULL) {
                tmp = tmp->left;
                path.push_back(tmp);
            }
        }
        
        return num;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return path.size() > 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */