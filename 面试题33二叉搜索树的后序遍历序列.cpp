class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        int n = postorder.size();
        if (n <= 2)
            return true;
        return check(postorder, 0, n-1);
    }

    bool check(vector<int>& postorder, int l, int r) {
        if (l >= r)
            return true;
        int root = postorder[r];
        int i, j;
        for (i = l; i < r; ++i)
            if (postorder[i] > root) 
                break;
        for (j = r-1; j >= l; --j)
            if (postorder[j] < root)
                break;
        if (j == l-1 || i == r)
            return check(postorder, l, r-1);
        if (i != j + 1)
            return false;
        return check(postorder, l, j) && check(postorder, i, l); 
    }
};