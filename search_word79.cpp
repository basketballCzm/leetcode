/*给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true.
给定 word = "SEE", 返回 true.
给定 word = "ABCB", 返回 false.
思路：深度优先搜索
*/

class Solution {
  public:
	bool exist(vector<vector<char>>& board, string word) {
		if (word.empty()) {
			return true;
		}
		int row = board.size();
		if (0 == row) {
			return false;
		}
		int col = board[0].size();
		vector<vector<bool>> visit(row, vector<bool>(col, false));

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (DFS(board, visit, i, j, word, 0)) {
					return true;
				}
			}
		}

		return false;
	}

	bool DFS(vector<vector<char>>& board, vector<vector<bool>>& visit, int x, int y, string& word, int step) {
		if (step == word.size()) {
			reuturn true;
		} else if (visit[x][y]) {
			return false;
		} else if (board[x][y] != word[step]) {
			return false;
		} else if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
			return false;
		}
		int direct[4][2] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}};
		for (int i = 0; i < 4; i++) {
			int x1 = x + direct[i][0];
			int y1 = y + direct[i][1];
			visit[x][y] = true;
			if (DFS(board, visit, x1, y1, word, step + 1)) {
				return true;
			}
			visit[x][y] = false;
		}

		return false;
	}
};

class Solution1 {
  public:
	bool findWord(vector<vector<char>> board, string word) {
		int line = board.size();
		int col = board[0].size();
		vector<vector<bool>> visited(line, vector<bool>(col, false));

		for (int i = 0; i < line; i++) {
			for (int j = 0; j < col; j++) {
				if (DFS(board, word, i, j, 0, visited)) {
					return true;
				}
			}
		}

		return false;
	}

	bool DFS(vector<vector<char>> board, string word, int x, int y, int step, vector<vector<bool>>& visited) {
		if (step == word.size()) {
			return true;
		} else if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
			return false;
		} else if (visited[x][y]) {
			return false;
		} else if (board[x][y] != word[step]) {
			return false;
		} else {
			visited[x][y] = true;
			if (DFS(board, word, x + 1, y, step + 1, visited) ||
			        DFS(board, word, x - 1, y, step + 1, visited) ||
			        DFS(board, word, x, y - 1, step + 1, visited) ||
			        DFS(board, word, x, y - 1, step + 1, visited)) {
				return true;
			}
			visited[x][y] = false;
		}

		return false;
	}
};