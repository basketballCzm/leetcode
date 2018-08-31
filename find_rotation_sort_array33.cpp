/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
*/

/*
思路： 先查找到有序数组，然后再进行二分搜素
if(L[mid] >= L[letft])//左边有序
{
	if(target <=  L[mid] && target >= L[left]){
	开始二分查找
	}
	continue；
}else{                //右边有序
	if(target >= L[mid] && target <= L[right]){
	开始二分查找
	}
	continue;
}
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if(0 == size){
        	return -1;
        }
        int mid = 0;
        int left = 0;
        int right = size-1;
        while(left <= right){
        	mid = left+(right-left)/2;
        	if(target == nums[mid]){
        		return mid;
        	}
        	if(nums[mid] >= nums[left]){ 
        		if(target <= nums[mid] && target >= nums[left]){
        			//开始二分查找
        			//return Binary_Search(nums, left, mid);
        			right = mid;
        		}else{
        			left = mid+1;
        		}
        	}else{
        		if(target >= nums[mid] && target <= nums[right]){
        			//return Binary_Search(nums, mid, right);
        			left = mid;
        		}else{
        			right = mid-1;
        		}
        	}
        }

        return -1;
    }
};
