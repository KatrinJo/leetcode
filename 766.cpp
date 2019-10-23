/*
进阶要求：
如果矩阵存储在磁盘上，并且磁盘内存是有限的，因此一次最多只能将一行矩阵加载到内存中，该怎么办？
如果矩阵太大以至于只能一次将部分行加载到内存中，该怎么办？

我的答案：新开一个空间。按照以下写法，每次加载进来的时候，把每个数要去的地方，根据这个数在矩阵中的位置对应起来。最后在新位置进行比较。
*/

class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		int m = matrix.size(), n;
		if (m == 0) return true;
		n = matrix[0].size();
		if (n == 0) return true;
		vector<vector<int>> newmatrix(m + n - 1, vector<int>());
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				newmatrix[i - j + n - 1].push_back(matrix[i][j]);
			}

		for (auto line : newmatrix) {
			if (line.size() <= 1)
				continue;
			int num = line[0];
			for (auto & v : line) {
				if (v != num)
					return false;
			}
		}
		return true;
	}
};
