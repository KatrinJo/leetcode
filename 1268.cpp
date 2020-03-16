class Solution {
public:
    struct Node{
        Node * child[26];
        bool stop;
        Node () {
            for (int i = 0; i < 26; ++i) {
                child[i] = NULL;
            }
            stop = false;
        }
    };

    Node * buildTree(vector<string>& products) {
        Node * root = new Node(), * curr;
        for (auto & p : products) {
            curr = root;
            for (auto c : p) {
                if (curr->child[c - 'a'] == NULL) {
                    curr->child[c - 'a'] = new Node();
                }
                curr = curr->child[c - 'a'];
            }
            curr->stop = true;
        }
        return root;
    }

    void fill(vector<string> & res, Node * root, string & prefix) {
        if (res.size() == 3)
            return;
        if (root->stop)
            res.push_back(prefix);
        for (int i = 0; i < 26; ++i) {
            if (root->child[i] == NULL)
                continue;
            prefix.push_back(i + 'a');
            fill(res, root->child[i], prefix);
            prefix.pop_back();
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = searchWord.length();
        if (n == 0) return {};
        vector<vector<string>> res(n);
        Node * root = buildTree(products);
        int i = 0;
        string prefix;
        for (i = 0; i < n; ++i) {
            if (root->child[searchWord[i] - 'a'] == NULL)
                break;
            prefix.push_back(searchWord[i]);
            fill(res[i], root->child[searchWord[i] - 'a'], prefix);
            root = root->child[searchWord[i] - 'a'];           
        }
        return res;
    }
};