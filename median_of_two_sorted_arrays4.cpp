/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。

请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。

你可以假设 nums1 和 nums2 不同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

中位数是 (2 + 3)/2 = 2.5
*/

/*
解题思路：相当于是两个链表或者数组进行时间复杂度为O(m+n)的合并操作，由于是有序的容器序列，先同时合并两个容器，直到一个容器序列
率先为空，然后将非空的容器序列直接添加到新的容器中。
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	vector<int> nums3;
    	vector<int>::iterator it_nums1 = nums1.begin();
    	vector<int>::iterator it_nums2 = nums2.begin();
    	while(it_nums1 != nums1.end() && it_nums2 != nums2.end()){
    		if(*it_nums1 > *it_nums2){
    			nums3.push_back(*it_nums2);
    			it_nums2++;
    		}else{
    			nums3.push_back(*it_nums1);
    			it_nums1++;
    		}
    	}

    	while(it_nums1 != nums1.end()){
    		nums3.push_back(*it_nums1);
    		it_nums1++;
    	}

    	while(it_nums2 != nums2.end()){
    		nums3.push_back(*it_nums2);
    		it_nums2++;
    	}

    	int num3 = nums3.size();
    	if(0 == num3){
    		return 0;
    	}else if(num3%2){
    		return nums3[num3/2];
    	}else{
    		return (double)(nums3[num3/2]+nums3[num3/2-1])/2;
    	}
    }
};