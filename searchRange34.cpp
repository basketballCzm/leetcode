/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
*/
/*
二分查找是解决有顺序序列的重要解决方法，本题是二分查找的变形，主要是在nums[mid] = target时候进一步对其进行改进
如果是找最左边的值，则每次要检查nums[mid-1] == target //注意校验mid>0
最右边的值，每次检查nums[mid+1] == target
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	int left = 0;
    	vector<int> res;
    	int right = nums.size()-1;
    	//防止nums[mid]崩溃  nums.size()-1
    	int mid = 0;

    	//找到最左边的值
    	while(left <= right){
    		mid = (left+right)/2;
    		if(nums[mid] < target){
    			left = mid+1;
    		}else if(nums[mid] > target){
    			right = mid-1;
    		}else{
    			//先求left的值，查看当前查找元素的后一个元素，看看是否和target相等
    			if(mid > 0 && nums[mid-1] == target){
    				//相当于中间节点往后移动一位或者不移动
    				right--;
    			}else{
    				res.push_back(mid);
    				break;
    			}
    		}
    	}

    	if(0 == res.size()){
    		res.push_back(-1);
    		res.push_back(-1);
    		return res;
    	}

    	//找到最右边的值
    	left = 0;
    	right = nums.size();
    	while(left <= right){
    		mid = (left+right)/2;
    		if(nums[mid] < target){
    			left = mid+1;
    		}else if(nums[mid] > target){
    			right = mid-1;
    		}else{
    			if(nums[mid+1] == target){
    				left++;
    			}else{
    				res.push_back(mid);
    				break;
    			}
    		}
    	}

    	return res;
    }
};
