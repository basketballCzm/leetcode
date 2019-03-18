/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

示例 1:

给定 nums = [1,1,1,2,2,3],

函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,0,1,1,1,1,2,3,3],

函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。

你不需要考虑数组中超出新长度后面的元素。
说明:

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}

思路：根据当nums[i] != nums[j]时，两者的差值来进行分类讨论。
当差值小于1 i++ j++
差值为2 i = j j++
差值大于2 移动位数，并且改变size的大小。

*/

class Solution {
  public:
	int removeDuplicates(vector<int>& nums) {
		int size = nums.size();
		if (size <= 2) {
			return size;
		}
		int i = 0, j = i + 1;
		while ( i < size) {
			//while (nums[i] == nums[j] && j < size) {
			//这里j==size时候的情况在移动位数时没有影响。
			while (j < size && nums[i] == nums[j]) {
				j++;
			}
			if (j - i <= 1) {
				i++;
				j++;
			} else if (2 == j - i) {
				i = j;
				j++;
			} else if (j - i >= 2) {
				for (int k = i + 2, z = j; z < size; z++, k++) {
					nums[k] = nums[z];
				}
				size = size - (j - i - 2);
				i = i + 2;
				j = i + 1;
			}
		}

		return size;

	}
};


//将可以冲重复的元素进行技术，可以重复几次。在两者pre cur两者不相等和可以重复的次数下，都有进行A[++pre]=A[cur++]的赋值。
//在两者相等和重复次数达到0的情况下cur++即可。
class Solution {
  public:
	int removeDuplicates(int A[], int n) {
		if (n <= 2) return n;
		int pre = 0, cur = 1, count = 1;
		while (cur < n) {
			if (A[pre] == A[cur] && count == 0) ++cur;
			else {
				if (A[pre] == A[cur]) --count;
				else count = 1;
				//当前元素赋值给当前重新计数的后面一个元素
				A[++pre] = A[cur++];
			}
		}
		return pre + 1;
	}
};