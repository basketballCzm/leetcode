/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？



网格中的障碍物和空位置分别用 1 和 0 来表示。

说明：m 和 n 的值均不超过 100。

示例 1:

输入:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
输出: 2
解释:
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右

1. dp时间复杂度能够通过
2. DFS会超时
*/


class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1));

        //初始化dp，当dp第一行或者第一列存在1时，1后面的元素就全部为0不能到达
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (1 == obstacleGrid[i][0]) {
                flag = 1;
            }

            if (flag) {
                dp[i][0] = 0;
            }
        }

        flag = 0;
        for (int i = 0; i < m; i++) {
            if (1 == obstacleGrid[0][i]) {
                flag = 1;
            }

            if (flag) {
                dp[0][i] = 0;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (1 == obstacleGrid[i][j]) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[n - 1][m - 1];
    }
};