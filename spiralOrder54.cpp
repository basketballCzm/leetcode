/*

给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(0 == matrix.size() || 0 == matrix[0].size()){
            return res;
        }
        int rows = matrix.size()-1;
        int cols = matrix[0].size()-1;
        int up = 0, bottom = rows, left = 0, right = cols;

        while(true){
            for(int i = left; i <= right; i++){res.push_back(matrix[up][i]);}
            if(++up > bottom){break;}
            for(int i = up; i <= bottom; i++){res.push_back(matrix[i][right]);}
            if(--right < left){break;}
            for(int i = right; i >= left; i--){res.push_back(matrix[bottom][i]);}
            if(--bottom < up){break;}
            for(int i = bottom; i >= up; i--){res.push_back(matrix[i][left]);}
            if(++left > right){break;}
        }

        return res;
    }
};