/*
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
示例 1:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
输出: true
示例 2:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
输出: false
*/

/*
由于二维矩阵是升序排列，可以先找到行号，再再到列号，避免遍历整个二维数组。但是这样要注意边界值的情况
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	if(matrix.empty()){
    		return false;
    	}
    	int size = matrix.size();
    	int size1 = matrix[0].size();
    	for(int i = 0; i < size; i++){
    		if(i == size-1 || (matrix[i][0] <= target && matrix[i+1][0] > target)){
    			for(int j = 0; j < size1; j++){
    				if(matrix[i][j] == target){
    					return true;
    				}
    			}
    			return false;
    		}
    	}

    	return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	if(matrix.empty()){
    		return false;
    	}
    	int size = matrix.size();
    	if(1 == size && matrix[0].empty()){
    		return false;
    	}
    	int size1 = matrix[0].size();
    	for(int i = 0; i < size; i++){
    		if(matrix[i][0] > target){
    			break;
    		}
    		for(int j = 0; j < size1; j++){
    			if(target == matrix[i][j]){
    				return true;
    			}else if(matrix[i][j] > target){
    				break;
    			}
    		}
    	}

    	return false;
    }
};