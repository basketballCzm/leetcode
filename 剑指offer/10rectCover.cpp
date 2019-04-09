题目描述
我们可以用2 * 1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2 * 1的小矩形无重叠地覆盖一个2 * n的大矩形，总共有多少种方法

依旧是斐波拉契数列
class Solution {
  public:
	int rectCover(int number) {
		if (0 == number) {
			return 0;
		} else if (1 == number) {
			return 1;
		} else if (2 == number) {
			return 2;
		}

		vector<int> v(number, 1);
		v[0] = 1;
		v[1] = 2;
		for (int i = 2; i < number; i++) {
			v[i] = v[i - 1] + v[i - 2];
		}

		return v[number - 1];
	}
};