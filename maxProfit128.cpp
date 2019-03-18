/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

思路： 可以将问题分为3中情况，买入和卖出时间都在左半部，买入和卖出时间都在右半部，买入和卖出时间横跨中点，买入在左半部，卖出在右半部
还有简单的思路：遍历的同时记录已经遍历过的最小值，然后求当前值与最小值之间的差值
*/

class Solution {
  public:
	int maxProfit(vector<int>& prices) {
		return maxProfitR(prices, 0, prices.size() - 1);
	}

	int maxProfitR(vector<int>& prices, int left, int right) {
		if (left >= right) {
			return 0;
		}

		int mid = (left + right) / 2;
		int left_max = maxProfitR(prices, left, mid);
		int right_max = maxProfitR(prices, mid + 1, right);
		int across_max = acrossMaxProfitR(prices, left, mid , right);
		if (left_max >= right_max && left_max >= across_max) {
			return left_max;
		} else if (right_max >= left_max && right_max >= across_max) {
			return right_max;
		}
		return across_max;
	}

	int acrossMaxProfitR(vector<int>& prices, int left, int mid, int right) {
		int sum_max = INT_MIN;
		for (int i = left; i <= mid; i++) {
			for (int j = mid + 1; j <= right; j++) {
				if (prices[j] > prices[i]) {
					if (sum_max < prices[j] - prices[i]) {
						sum_max = prices[j] - prices[i];
					}
				}
			}
		}

		if (INT_MIN == sum_max) {
			return 0;
		}

		return sum_max;

	}
};


class Solution {
  public:
	int maxProfit(vector<int>& prices) {
		int res = 0, min_price = INT_MAX;
		for (auto price : prices) {
			min_price = min(min_price, price);
			res = max(res, price - min_price);
		}

		return res;
	}
};