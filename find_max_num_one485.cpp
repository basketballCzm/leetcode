/*

给定一个二进制数组， 计算其中最大连续1的个数。

示例 1:

输入: [1,1,0,1,1,1]
输出: 3
解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
注意：

输入的数组只包含 0 和1。
输入数组的长度是正整数，且不超过 10,000。
*/

#include <iostream>
#include <vector>

class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
    	int num = nums.size();
    	//用一个值来维护当前的1长度
    	int len = 0;
    	//用一个最大值来维护当前的最大长度 
    	int max = 0;
        for(int i = 0; i < num; i++){
        	if(nums[i] == 1){
        		len++;
        	}else if(nums[i] == 0){
        		if(len > max){
        			max = len;
        		}
        		len = 0;
        	}
        }

        return max>len?max:len;
    }
};

int main(){
	Solution s;
	std::vector<int> v(10,1);
	std::cout << s.findMaxConsecutiveOnes(v) <<std::endl;
	return 0;
}