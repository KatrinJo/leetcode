// 很有趣，每次都处理左子树中最大数的结点，将它放在root和root->right之间，
// 接下来root被设置为左子，继续处理左子的左子树中最大数的结点。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root != nullptr) {
            while(root != nullptr) {
                if (root->left != nullptr) {
                    auto r = root->left;
                    while(r->right != nullptr) 
                        r = r->right;
                    r->right = root->right;
                    root->right = root->left;
                    root->left = nullptr;
                }
                root = root->right;
            }
        }
    }
};


// 这里还有道类似的题目
// https://blog.csdn.net/da_kao_la/article/details/89007032
// 【二叉树形态变换】给定一个用中序遍历定义的二叉搜索树，用in-place的算法把二叉树变成有序链表，其中链表用左子树为null的二叉树等价表示。下面是例子，其中N表示null：
// 用类似的写法把这道题写了一下
class Solution2 {
public:
	void flatten(Node * root) {
		if (root != nullptr) {
			while (root != nullptr) {
				if (root->left != nullptr) {
					Node * r = root->left;
					while (r->right != nullptr)
						r = r->right;
					r->right = root;
					r = root->left;
					root->left = nullptr;
					root = r;
				}
				root = root->right;
			}
		}
	}
};