/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例 1:

输入: [2,3,1,1,4]
输出: true
解释: 从位置 0 到 1 跳 1 步, 然后跳 3 步到达最后一个位置。
示例 2:

输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
*/

/*
解题思路:1.相当于迷宫搜素问题，在当前位置一共有多少中行走的可能性，对所有的可能性依次进行深度优先搜索,这样做测试用例74 / 75，时间超过限制

2. 贪心算法:计算当前跳跃步数能够达到的最远距离，如果能够达到最远距离说明能够到达
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
    	return canJumpStep(nums, 0);
    }

    bool canJumpStep(vector<int>& nums, int index){
    	if(index > nums.size()-1){
    		return false;
    	}else if(index == nums.size()-1){
    		return true;
    	}

    	for(int i = 1; i <= nums[index]; i++){
    		if(canJumpStep(nums, index+i)){
    			return true;
    		}
    	}

    	return false;
    }
};
/*
解题思路：贪心算法，farest记录[0,farest_index]能够达到的最远距离,当遍历到最远距离farest_index后farest_index = farest,
然后继续查找[farest_index,farest]能够达到的最远距离
*/

class Solution{
public:
	bool canJump(vector<int>& nums){
		if(0 == nums.size() || 1 == nums.size()){
			return true;
		}
		int jumps = 0;
		int farest_index = 0;  //每一步最远距离的下标
		int farest = 0;        //每一步能够达到的最远距离
		int size = nums.size()-1;
		for(int i = 0; i < size; i++){
			farest = max(farest,i+nums[i]);
			if(i == farest_index){
				farest_index = farest;
				jumps++;
				if(farest >= size){
					return true;
				}
			}
		}

		return false;
		//return farest>=size?true:false;
	}
};