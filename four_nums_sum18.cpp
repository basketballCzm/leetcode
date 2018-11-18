/*

给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

/*
解题思路：K-SUM 的和，主要的解题思路是循环前面K-2个数字，然后最后两个数字用left和right，两个指针分别一个指针
从左往右，另一个指针从右往左进行扫描。注意在扫描过程中的去重。
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	int size = nums.size();
    	vector<vector<int>> res;
    	sort(nums.begin(), nums.end());
    	int left = 0;
    	int right = 0;
    	int sum = 0;
    	for(int i = 0; i < size-3; i++){
    		for(int j = i+1; j < size-2; j++){
    			left = j+1;
    			right = size-1;
    			while(left < right){
    				sum = nums[i] + nums[j] + nums[left] + nums[right];
    				if(target == sum){
    					res.push_back({nums[i],nums[j],nums[left],nums[right]});
    					while(left < right && nums[left] == nums[left+1]){left++;}
    					while(left < right && nums[right] == nums[right-1]){right--;}
    					left++;
    					right--;
    				}else if(target > sum){
    					left++;
    				}else{right--;}
    			}

                //防止重复的元组出现重复的j值
    			while(j < size-2 && nums[j] == nums[j+1]){j++;}
    		}

            //f防止重复的元组出现重复的i值
    		while(i < size-3 && nums[i] == nums[i+1]){i++;}
    	}

    	return res;
    }
};