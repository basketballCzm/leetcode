/*
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
/*
思路: 用四个标记分别记录上下左右四条边的当前位置，当完成从左到右的遍历后，上边下移1即up++，每完成一条边的填写，注意对相应的边下标记录进行加减运算。
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    	vector<vector<int>> matrix(n, vector<int>(n,0));
    	//螺旋遍历最重要的是确定上下左右四条边的位置
    	int left = 0, right = n-1, bottom = n-1, up = 0, val = 1;
    	while(true){
    		for(int i = left; i <= right; i++){matrix[up][i] = val++;}
    		if(++up > bottom){break;}
    		for(int i = up; i <= bottom; i++){matrix[i][right] = val++;}
    		if(--right < left){break;}
    		for(int i = right; i >= left; i--){matrix[bottom][i] = val++;}
    		if(--bottom < up){break;}
    		for(int i = bottom; i >= up; i--){matrix[i][left] = val++;}
    		if(++left > right){break;}
    	}

    	return matrix;
    }
};