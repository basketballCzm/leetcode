/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1
示例 2:

输入: [4,1,2,1,2]
输出: 4
*/
/*
排好序使用该数组的特性，使用STL unordered_map 或者 map
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	int size = nums.size();
    	int i,j;
    	for(i = 0; i < size; i++){
    		for(j = 0; j < size; j++){
    			if(i != j){
    				if(nums[i] == nums[j]){
    					break;
    				}
    			}
    		}

    		if(j == size){
    			return nums[i];
    		}
    	}
    }
};

class Solution{
public:
	int singleNumber(vector<int>& nums) {
		unordered_map<int,int> int_map;
		for(auto x : nums){
			int_map[x]++;
		}

		for(auto x : int_map){
			if(1 == x.second){
				return x.first;
			}
		}
	}
};

class Solution{
public:
	int singleNumber(vector<int>& nums){
		sort(nums.begin(), nums.end());
		for(int i = 0; i < nums.size()/2; i++){
			if(nums[2*i] != nums[2*i+1]){
				return nums[2*i];
			}
		}

		return nums[nums.size()-1];
	}
};




