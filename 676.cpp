// Trie字典树，使用的还不是很熟练……

class MagicDictionary {
    struct Node {
        char c;
        bool canStop;
        Node * child[26];

        Node(char _c = ' ') {
            c = _c;
            canStop = false;
            for (int i = 0; i < 26; ++i) {
                child[i] = nullptr;
            }
        }
        ~Node() {
            for (int i = 0; i < 26; ++i) {
                if (child[i] != nullptr) {
                    delete child[i];
                }
            }
        }
    };
    Node * root;
public:
    
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = nullptr;
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        root = new Node();
        Node * curr;
        for (auto & str : dict) {
            curr = root;
            for (auto & c : str) {
                if (curr->child[c - 'a'] == nullptr) 
                    curr->child[c - 'a'] = new Node(c);
                curr = curr->child[c - 'a'];
            }
            curr->canStop = true;
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return searchNode(root, word, 0, 1);
    }

    bool searchNode(Node * node, string & word, int idx, int rest) {
        if (word.length() < idx) return false;
        if (word.length() == idx) {
            if (rest != 0) return false;
            if (node->canStop) return true;
            return false;
        }
        Node * cnode = node->child[word[idx] - 'a'];
        int childidx = -1;
        if (rest == 0 && cnode == nullptr)
            return false;
        else if (rest == 0)
            return searchNode(cnode, word, idx + 1, 0);
         
        if (cnode != nullptr) 
            if (searchNode(cnode, word, idx + 1, 1)) 
                return true;
        
        for (int i = 0; i < 26; ++i) {
            cnode = node->child[i];
            if (cnode == nullptr) continue;
            if (i == word[idx] - 'a') continue;
            if (searchNode(cnode, word, idx + 1, 0))
                return true;            
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */