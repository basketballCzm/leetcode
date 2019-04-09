/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

class Solution {
  public:
	void reOrderArray(vector<int> &array) {
		//其实通过优化只用一个vector即可
		vector<int> odd;
		vector<int> parm;
		for (auto x : array) {
			if (0 == x % 2) {
				parm.push_back(x);
			} else {
				odd.push_back(x);
			}
		}

		odd.insert(odd.end(), parm.begin(), parm.end());
		array = odd;
	}
};

//采用冒泡排序的方式，内循环从后往前调动一个较大的值

//两个思路吧，第一个思路：类似冒泡算法，前偶后奇数就交换：
class Solution {
  public:
	void reOrderArray(vector<int> &array) {
		for (int i = 0; i < array.size(); i++) {
			for (int j = array.size() - 1; j > i; j--) {
				if (array[j] % 2 == 1 && array[j - 1] % 2 == 0) { //前偶后奇交换
					swap(array[j], array[j - 1]);
				}
			}
		}
	}
};


