/*
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
*/

/*
思路: 使用动态规划，每次记录一个坐标点的最小值。每一个点的值只可能是上方和左方的值来得到，通过选取两者中的最小值来得出该点的最小值。
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(0 == grid.size() || 0 == grid[0].size()){
            return 0;
        }
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m,1));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < n; i++){
            dp[i][0] = dp[i-1][0]+grid[i][0];
        }

        for(int i = 1; i < m; i++){
            dp[0][i] = dp[0][i-1]+grid[0][i];
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(dp[i-1][j] < dp[i][j-1]){
                    dp[i][j] = grid[i][j]+dp[i-1][j];
                }else{
                    dp[i][j] = grid[i][j]+dp[i][j-1];
                }
            }
        }
        

        return dp[n-1][m-1];
    }
};