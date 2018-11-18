/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
*/
/*
分治法的最佳体现基本步骤是:
1. 分解
将整个问题分成3种情况
1. 最大子数组在中点左边的数组中。
2. 最大子数组在中点右边的数组中。
3. 最大子数组在过中点的子数组中。

2. 解决:分别对上面的3个子问题求最大子数组之和
3. 合并:比较上面3个问题最大子数组之和的大小值，最大子数组之和即为本题的解。
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	if(nums.empty()){
    		return 0;
    	}


    	return find_max_substr(nums,0,nums.size()-1);
    }

    int find_max_substr(vector<int>& nums, int left, int right){
    	//相当于是结束条件,只有一个元素
    	if(left == right){
    		return nums[left];
    	}
    	int mid = (left+right)/2;
    	int left_value = find_max_substr(nums,left,mid);
    	int right_value = find_max_substr(nums,mid+1,right);
    	//从中间向两边进行延伸查找最大子数组
    	int value = find_max_substr_value(nums, left, right);
    	if(left_value >= value && left_value >= right_value){
    		return left_value;
    	}else if(right_value >= value && right_value >= left_value){
    		return right_value;
    	}else{
    		return value;
    	}
    }

    int find_max_substr_value(vector<int>& nums, int left, int right){
    	int mid = (left+right)/2;
    	int left_index = 0,left_sum = INT_MIN;
    	int right_index = 0,right_sum = INT_MIN;

    	int sum = 0;
    	for(int i = mid; i >= left; i--){
    		sum += nums[i];
    		if(sum > left_sum){
    			left_index = i;
    			left_sum = sum;
    		}
    	}

    	sum = 0;

    	for(int i = mid+1; i <= right; i++){
    		sum += nums[i];
    		if(sum > right_sum){
    			right_index = i;
    			right_sum = sum;
    		}
    	}

    	return left_sum+right_sum;
    }
};