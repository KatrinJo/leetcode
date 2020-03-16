class Trie {
public:
    /** Initialize your data structure here. */
    class Node {
    public:
        Node * child[26];
        bool stop;
        Node () {
            for (int i = 0; i < 26; ++i)
                child[i] = NULL;
            stop = false;
        }
    };
    Node * root;
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node * tmp = root;
        for (auto c : word) {
            if (tmp->child[c - 'a'] == NULL) {
                tmp->child[c - 'a'] = new Node();
            }
            tmp = tmp->child[c - 'a'];
        }
        tmp->stop = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node * tmp = root;
        for (auto c : word) {
            if (tmp->child[c - 'a'] == NULL) return false;
            tmp = tmp->child[c - 'a'];
        }
        return tmp->stop;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node * tmp = root;
        for (auto c : prefix) {
            if (tmp->child[c - 'a'] == NULL) return false;
            tmp = tmp->child[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */