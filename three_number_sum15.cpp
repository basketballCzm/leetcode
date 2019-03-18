/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

/*
解题思路：按照常规解法3层for循环进行遍历，找出3个数之和为0的组别，然后再校验该组是否在返回的容器中存在，
如果不存在就将该容器存入。注意这里的比较是否相等不能使用==重载，因为可能元素一样，但是元素顺序不一样，这样也会
导致重载的函数判定两个容器不一样   能够跑通大部分的测试用例，但是对于数据量大后提交上去会超过时间限制


这个思路最重要的是首先要对vector进行排好序
改进思路：由于是3个数相加等于零，必定有两个数一个为正数一个为负数，或者3个数都为0，这样现将vector排好序，然后遍历
每一个数，如果是负数就先固定这个数，然后持续移动后面的一串数，左边的数下标加加，右边的数下标减减。注意对于重复的数字要先算
第一次重复出现的数字，不算第一次之后重复出现的数字
*/
class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i = 0; i < size - 2; i++) {
            if (nums[i] > 0) {
                return res;
            } else {
                int j = i + 1;
                int k = size - 1;
                while (j < k) {
                    if (0 == nums[i] + nums[j] + nums[k]) {
                        res.push_back({nums[i], nums[j], nums[k]});
                        //这里是去重操作
                        while (j < k && nums[j] == nums[j + 1]) {j++;}
                        while (j < k && nums[k] == nums[k - 1]) {k--;}
                        j++;
                        k--;
                    } else if (0 < nums[i] + nums[j] + nums[k]) {k--;}
                    else {j++;}
                }
            }

            //算第一个重复的数字，不算第一个之后的重复的数字
            while (nums[i] == nums[i + 1]) {
                i++;
            }
        }

        return res;
    }
};
