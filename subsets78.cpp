/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
思路：按照子集个数分别为1,2,3,4,5分别使用DFS进行求解子集合
*/

class Solution {
  public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int size = nums.size();
		vector<vector<int>> res;
		for (int i = 1; i <= size; i++) {
			vector<int> subnums;
			subsetsR(nums, i, 0, subnums, res);
		}

		res.push_back([]);

		return res;
	}

	void subsetsR(vector<int>& nums, int cnt, int step, vector<int> subnums, vector<vector<int>>& res) {
		if (subnums.size() == cnt) {
			res.push_back(subnums);
			return;
		} else if (step >= nums.size()) {
			return;
		}

		for (int i = step; i < nums.size(); i++) {
			subnums.push_back(nums[i]);
			subsetsR(nums, cnt, i + 1, subnums, res);
			subnums.pop_back();
		}



	}
};


class Solution {
  public:

	vector<vector<int>> res;
	vector<bool> visit;
	void permuten(vector<int>& nums, int p, vector<int>& tmp, int count, int begin) { //p:位置 表示当前 执行到要确定 哪一个位置了
		if (p == count) {
			res.push_back(tmp);
			return;
		}
		for (int i = begin; i < nums.size(); i++) {
			if (!visit[i]) {
				visit[i] = true;//!!!  一定加上 改变 visit
				tmp.push_back(nums[i]);//当前位置上的数确定了
				//继续确定下一个位置
				permuten(nums, p + 1, tmp, count, i + 1);

				//执行到这里  表示所有位置上的数已经确定了 本次可以结束了
				//弹出当前的数  看还有没有其他可能
				//回溯
				tmp.pop_back();
				//!!!  一定加上 改变 visit
				visit[i] = false;

			}

		}

	}

	vector<vector<int>> subsets(vector<int>& nums) {
		res.clear();
		if (nums.size() == 0) return {};


		res.push_back({});
		for (int i = 1; i < nums.size() + 1; i++) {
			vector<int> tmp;
			visit = vector<bool>(i, false); //vector赋值
			permuten(nums, 0, tmp, i, 0);
		}



		return res;
	}
};
