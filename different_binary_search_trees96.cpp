/*96
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
示例:
输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
/*
解题思路：计算一共有多少种排列方式，也是依次将start 到 end 依次作为根节点，分别计算左右两边可能出现的情况，具体思路
根节点 j 区间范围是1-i  那么这一趟的可能情况dp[j-1]*dp[i-j]。由于这道题目使用递归的方式在比较大的数据不能通过，因此使用非递归
的递推方式来完成，注意初始化dp[0]=dp[1]=1
*/


#include <iostream>
class Solution{
public:
	int numTrees(int n){
		std::vector<int> dp(n+1, 0);
		//初始化dp[0]=dp[1]=0;因为情况0和1都是只有一种情况，先搜索一个数当根节点，然后左右两边按照相同的方法递归
		dp[0] = dp[1] = 1;
		//非递归的方法
		for(int i = 2; i <= n; i++){ //用于dp[i]的递推式,每次循环得到一个dp[]的值
			for(int j = 1; j <= i; j++){ //用于划分值，在递推的过程中分别取划分值
				dp[i] += dp[j-1]*dp[i-j];
			}
		}

		return dp[n];
	}

	//递归超过时间限制
	int r_numTrees(int n){
		if(0 == n || 1 == n){
			return 1;
		}
		//std::vector<int> dp(n+1, 0);
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			cnt += r_numTrees(i-1)*r_numTrees(n-i);
		}
		return cnt;
	}
private: 
};