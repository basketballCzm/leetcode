/*
统计一个数字在排序数组中出现的次数。
*/

class Solution {
  public:
	//一遍遍历的时间复杂度为O(n),如果需要进行一步的提高时间复杂度可以使用二分查找，k-0.5和k+0.5的要插入的位置
	int GetNumberOfK(vector<int> data , int k) {
		//int left = BinaryFind(data, k-0.5);
		//int right = BinaryFind(data, k+0.5);
		int left = BinaryFindLow(data, k);
		int right = BinaryFindHigh(data, k);

		return right - left;
	}

	int BinaryFind(vector<int> data, double target) {
		int left = 0;
		int right = data.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (data[mid] < target) {
				left = mid + 1;
			} else if (data[mid] > target) {
				right = mid - 1;
			}
		}

		return left;
	}

	int BinaryFindLow(vector<int> data, int target) {
		int left = 0;
		int right = data.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (data[mid] >= target) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}

		return left;
	}

	int BinaryFindHigh(vector<int> data, int target) {
		int left = 0;
		int right = data.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (data[mid] <= target) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}

		return left;
	}
};