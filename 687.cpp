/*
微软面试过，但是当时纠结于自顶向下。突然发现自底向上才是正道（递归）。
官方题解比较简洁。
*/

class Solution {
public:
	int maxLen;

	int down2up(TreeNode* root) {
		
		if (root->left == NULL && root->right == NULL)
			return 0;
		int l = 0, r = 0;
		if (root->left == NULL) {
			r = down2up(root->right);
			if (root->val == root->right->val)
				return r + 1;
			else {
				maxLen = maxLen > r ? maxLen : r;
				return 0;
			}		
		}
		else if (root->right == NULL) {
			l = down2up(root->left);
			if (root->val == root->left->val)
				return l + 1;
			else {
				maxLen = maxLen > l ? maxLen : l;
				return 0;
			}
		}
		else {
			l = down2up(root->left);
			r = down2up(root->right);
			if (root->left->val != root->val && root->right->val != root->val) {
				maxLen = maxLen > l ? maxLen : l;
				maxLen = maxLen > r ? maxLen : r;
				return 0;
			}
			else if (root->right->val != root->val) {
				maxLen = maxLen > r ? maxLen : r;
				return l + 1;
			}
			else if (root->left->val != root->val) {
				maxLen = maxLen > l ? maxLen : l;
				return r + 1;
			}
			else {
				maxLen = maxLen > (l + r + 2) ? maxLen : (l + r + 2);
				return l > r ? l + 1 : r + 1;
			}
		}
	}

	int longestUnivaluePath(TreeNode* root) {
		if (root == NULL)
			return 0;
		maxLen = 0;
		int tmp = down2up(root);
		maxLen = maxLen > tmp ? maxLen : tmp;
		return maxLen;
	}
};
