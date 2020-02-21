// 好难顶这题……

/**
 * Definition for a binary tree svnode.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if (root == NULL)
            return res;
        vector<TreeNode*> myvec;
        TreeNode* tmp;
        int l = 0, r = 1;
        myvec.push_back(root);
        while(l < r) {
            tmp = myvec[l];
            ++l;
            res += to_string(tmp->val);
            if (tmp->left == NULL && tmp->right == NULL) {}
            else if (tmp->left == NULL) {
                res.push_back('r');
                myvec.push_back(tmp->right);
                ++r;
            }
            else if (tmp->right == NULL) {
                res.push_back('l');   
                myvec.push_back(tmp->left);
                ++r;
            }
            else {
                res.push_back('b');
                myvec.push_back(tmp->left);
                myvec.push_back(tmp->right);
                r += 2;
            }
            res.push_back(',');
        }
        // res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int len = data.size();
        if (len == 0)
            return NULL;

        vector<pair<TreeNode*, char>> myque;

        vector<string> sv;
        istringstream iss(data);
        string str, svnode;
        while(getline(iss, str, ','))
            sv.emplace_back(move(str));
        int n = sv.size(), idxsv = 1, val = stoi(sv[0]);
        char c = *(sv[0].rbegin());
        TreeNode * root = new TreeNode(val);
        TreeNode * tmp;
        int s = 0, e = 1;
        myque.push_back(make_pair(root, c));
        while(s < e && idxsv < n) {
            auto & x = myque[s];
            ++s;
            tmp = x.first;
            c = x.second;
            if (c == 'b') {
                svnode = sv[idxsv];
                val = stoi(sv[idxsv]);
                ++idxsv;
                c = *(svnode.rbegin());
                tmp->left = new TreeNode(val);
                if (c == 'b' || c == 'l' || c == 'r') {
                    myque.push_back(make_pair(tmp->left, c));
                    ++e;
                }
            
                svnode = sv[idxsv];
                val = stoi(sv[idxsv]);
                ++idxsv;
                c = *(svnode.rbegin());
                tmp->right = new TreeNode(val);
                if (c == 'b' || c == 'l' || c == 'r') {
                    myque.push_back(make_pair(tmp->right, c));
                    ++e;
                }
            }
            else if (c == 'l') {
                svnode = sv[idxsv];
                val = stoi(sv[idxsv]);
                ++idxsv;
                c = *(svnode.rbegin());
                tmp->left = new TreeNode(val);
                if (c == 'b' || c == 'l' || c == 'r') {
                    myque.push_back(make_pair(tmp->left, c));
                    ++e;
                }
            }
            else if (c == 'r') {
                string svnode = sv[idxsv];
                val = stoi(sv[idxsv]);
                ++idxsv;
                c = *(svnode.rbegin());
                tmp->right = new TreeNode(val);
                if (c == 'b' || c == 'l' || c == 'r') {
                    myque.push_back(make_pair(tmp->right, c));
                    ++e;
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));