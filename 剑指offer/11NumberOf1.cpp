/*
题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/

class Solution {
  public:
	int  NumberOf1(int n) {
		int cnt = 0;

		//其中负数用补码表示  负数除符号位外取反，然后加一
		while (0 != n) {
			cnt++;
			//n=10100  n-1=10011  n&n-1=10000 第3位1变成了0
			//这样写当为负数时候左边会填充1，陷入死循环
			//n = n >> 1;
			n = (n - 1) & n;
		}
		return cnt;
	}
};

//设置一个flag每次向左移动一位
class Solution {
  public:
	int  NumberOf1(int n) {
		int cnt = 0;
		int flag = 1;
		while (flag) {
			if ((n & flag) != 0) {
				cnt++;
			}
			flag = flag << 1;
		}

		return cnt;
	}
};
