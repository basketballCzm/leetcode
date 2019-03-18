/*
给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

示例 1:

输入:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
示例 2:

输入:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
进阶:

一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个常数空间的解决方案吗？

思路: 我觉的使用使用O(m+n)的额外空间更能够节省时间复杂度
*/
class Solution {
  public:
	void setZeroes(vector<vector<int>>& matrix) {
		int row = matrix.size();
		int col = 0;
		if (0 != row) {
			col = matrix[0].size();
		}

		vector<int> flag_row(row, 0);
		vector<int> flag_col(col, 0);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (0 == matrix[i][j]) {
					flag_row[i] = 1;
					flag_col[j] = 1;
				}
			}
		}

		for (int i = 0; i < row; i++) {
			if (1 == flag_row[i]) {
				for (int j = 0; j < col; j++) {
					matrix[i][j] = 0;
				}
			}
		}

		for (int i = 0; i < col; i++) {
			if (1 == flag_col[i]) {
				for (int j = 0; j < row; j++) {
					matrix[j][i] = 0;
				}
			}
		}
	}
};


//这种方法其实综合起来更好，因为这种方法没有使用额外的空间，其实算时间复杂度这个算法最坏是的O(n^3)次方，但是实际运行起来这里的时间复杂度更好
class Solution {
  public:
	void setZeroes(vector<vector<int>>& matrix) {
		int rows = matrix.size();
		int cols = 0;
		if (rows != 0) {
			cols = matrix[0].size();
		}
		if (rows == 0 || cols == 0) {
			return;
		}
		for (int i = 0; i < rows; i++) {
			for (int j  = 0; j < cols; j++) {
				if (matrix[i][j] == 0) {
					for (int k = 0; k < cols; k++) {
						if (matrix[i][k] != 0) {
							matrix[i][k] = '*';
						}
					}
					for (int k = 0; k < rows; k++) {
						if (matrix[k][j] != 0) {
							matrix[k][j] = '*';
						}
					}
				}
			}
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (matrix[i][j] == '*')
					matrix[i][j] = 0;
			}
		}
	}
};


