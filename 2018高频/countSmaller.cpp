/*
给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

示例:

输入: [5,2,6,1]
输出: [2,1,1,0]
解释:
5 的右侧有 2 个更小的元素 (2 和 1).
2 的右侧仅有 1 个更小的元素 (1).
6 的右侧有 1 个更小的元素 (1).
1 的右侧有 0 个更小的元素.
*/

/*
1. 使用二分搜素法进行插入元素
2. 使用二叉搜索树来代替第一问中的vector容器。
*/

//使用二分搜索法进行元素的插入,即对元素组从右到左依次将元素使用二分搜索法插入到有序序列容器t当中。
class Solution {
  public:
	vector<int> countSmaller(vector<int>& nums) {
		vector<int> t, res(nums.size());

		for (int i = nums.size() - 1; i >= 0; i--) {
			int left = 0;
			//right = t.size() 能避免边界值为空时候的校验工作。
			int right = t.size();
			while (left < right) {
				int mid = (left + right) / 2;
				//这一这里必须要是大于等于符号，因为题目中是右边小于当前元素的值
				if (t[mid] >= nums[i]) {
					right = mid;
				} else {
					left = mid + 1;
				}
			}

			res[i] = right;
			t.insert(t.begin() + right, nums[i]);
		}

		return res;
	}
};