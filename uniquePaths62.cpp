/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？

例如，上图是一个7 x 3 的网格。有多少可能的路径？

说明：m 和 n 的值均不超过 100。

示例 1:

输入: m = 3, n = 2
输出: 3
解释:
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右
示例 2:

输入: m = 7, n = 3
输出: 28
*/
/*
1. DFS 超时
2. 数学解法巧妙
3. DP  dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
*/

class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int step = 0;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        DFS(obstacleGrid, m, n, 0, 0, step);
        return step;
    }

    void DFS(vector<vector<int>>& obstacleGrid, int m, int n, int x, int y, int& step) {
        if (x >= m || y >= n) {
            return;
        } else if (1 == obstacleGrid[y][x]) {
            return;
        } else if (m - 1 == x && n - 1 == y) {
            step++;
            return;
        } else {
            DFS(obstacleGrid, m, n, x + 1, y, step); //向右
            DFS(obstacleGrid, m, n, x, y + 1, step); //向下
        }
    }
};

//数学解法输入7 3 相当于向右走6步，向下走2步。总步数为8，C8 2。
class Solution {
  public:
    int uniquePaths(int m, int n) {
        unsigned long x = 1;
        unsigned long y = 1;
        int small = m > n ? n : m;
        for (int i = 0; i < small - 1; i++) {
            x *= m + n - 2 - i;
            y *= (i + 1);
        }

        return (int)(x / y);

    }
};

//动态规划DP 到达该点一共有几条路
class Solution {
  public:
    int uniquePaths(int m, int n) {
        //第一行和第一列的值都为1
        vector<vector<int>> dp(n, vector<int>(m, 1));
        //可以只使用一维数组通过行或列进行递推

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[n - 1][m - 1];
    }
};


