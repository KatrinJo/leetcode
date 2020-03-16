/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        Node * res = NULL, * curr, * next, * tmp;
        curr = res;
        tmp = head;
        vector<Node*> myvec;
        map<Node*, Node*> arr;
        map<Node*, int> mapidx;
        int i = 0;
        while(tmp != NULL) {
            next = new Node(tmp->val);
            myvec.push_back(next);
            mapidx[tmp] = i++;
            if (tmp->random != NULL)
                arr[next] = tmp->random;
            if (curr == NULL) {
                res = curr = next;
            }
            else {
                curr->next = next;
                curr = next;
            }
            next = curr->next;            
            tmp = tmp->next;
        }

        tmp = head;
        for (i = 0; tmp != NULL; ++i, tmp = tmp->next) {
            if (tmp->random != NULL) {
                auto it = arr[myvec[i]];
                myvec[i]->random = myvec[mapidx[it]];
            }
        }    
        return res;    
    }
};