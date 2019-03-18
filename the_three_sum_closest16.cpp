/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/

class Solution {
  public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        //这里min初始值的选取不能比较有争议， 不知道如何选取
        //int min = 100000;
        if (size <= 3) {
            return 0;
        }
        min = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < size - 2; i++) {
            int left = i + 1;
            int right = size - 1;
            while (left < right) {
                if (target == nums[left] + nums[right] + nums[i]) {
                    //这里应该可以就直接退出了
                    min = target;
                    while (left < right && nums[left] == nums[left + 1]) {left++;}
                    while (left < right && nums[right] == nums[right - 1]) {right--;}
                    left++;
                    right--;
                } else if (nums[left] + nums[right] + nums[i] < target) {
                    if (abs(nums[left] + nums[right] + nums[i] - target) < abs(min - target)) {
                        min = nums[left] + nums[right] + nums[i];
                    }
                    left++;
                } else {
                    if (abs(nums[left] + nums[right] + nums[i] - target) < abs(min - target)) {
                        min = nums[left] + nums[right] + nums[i];
                    }
                    right--;
                }
            }

            while (i < size - 2 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        return min;
    }
};