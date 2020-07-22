#include "bits/stdc++.h"
#include <vector>

using namespace std;

class Node
{
public:
	vector<Node *> child;
	int val;
	Node(int v = 0) {
		child.clear();
		val = v;
	}
};

// 1st method
void dfs(Node * root, bool first, bool second, Node *res, Node *a, Node *b) {
	if (root == NULL || res != NULL)
		return;
	bool flag = false;
	if (!first && !second)
		flag = true;
	first = root == a ? true : first;
	second = root == b ? true : second;
	for (auto c : root->child)
		dfs(c, first, second, res, a, b);
	if (flag && first && second) {
		first = second = false;
		res = root;
	}
}

Node * LCA(Node *a, Node *b, Node * root) {
	if (a == NULL || b == NULL || root == NULL) {
		return NULL;
	}
	Node * res = NULL;
	dfs(root, false, false, res, a, b);
	return res;
}

map<Node*, vector<Node*>> path;


// 2nd method
void rebuild(Node * root, vector<Node*> p) {
	if (root == NULL)
		return;
	for (auto c : p) {
		path[root].push_back(c);
	}
	// path[root] = p;
	p.push_back(root);
	for (auto c : root->child)
		rebuild(c, p);
	p.pop_back();
}

int main() {
	Node * root = new Node(1);
	root->child.push_back(new Node(2));
	root->child.push_back(new Node(3));
	root->child.push_back(new Node(4));
	root->child.push_back(new Node(5));
	root->child[0]->child.push_back(new Node(6));
	root->child[0]->child.push_back(new Node(7));
	root->child[1]->child.push_back(new Node(8));
	root->child[2]->child.push_back(new Node(6));
	vector<Node*> p;
	rebuild(root, p);
	cout << endl;
	return 0;
}