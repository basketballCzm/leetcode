/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
    	int size = height.size();
    	int max = -1;
    	for(int i = 0; i < size; i++){
    		for(int j = i+1; j < size; j++){
    			int sum = height[i]>height[j]?(j-i)*height[j]:(j-i)*height[i];
    			max = max<sum?sum:max; 
    		}
    	}

    	return max;
    }

};