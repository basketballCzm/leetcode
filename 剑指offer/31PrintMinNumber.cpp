/*
题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/

//首先将vector中的整数转换为字符串，然后按照一定的方法进行排序，最后将排序的结果依次进行连接
//这道题我就是不明白如何将整数转化为字符串后如何比较大小，以及这样比较大小的原因
class Solution {
  public:
	static bool cmp(int a, int b) {
		string str1;
		string str2;
		str1 = to_string(a) + to_string(b);
		str2 = to_string(b) + to_string(a);
		return str1 < str2;
	}

	string PrintMinNumber(vector<int> numbers) {
		string res;
		//sort后面的函数必须是静态函数成员
		sort(numbers.begin(), numbers.end(), cmp);
		for (int i = 0; i < numbers.size(); i++) {
			res += to_string(numbers[i]);
		}

		return res;
	}
};