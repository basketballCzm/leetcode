/*
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/

class Solution {
  public:
	//使用两个栈来处理，辅助栈就只存储较小的数
	stack<int> stk1, stk2;
	void push(int value) {
		stk1.push(value);
		if (stk2.empty()) {
			stk2.push(value);
		} else if (value < stk2.top()) {
			stk2.push(value);
		}
	}
	void pop() {
		if (stk1.top() == stk2.top()) {
			stk2.pop();
		}
		stk1.pop();
	}
	int top() {
		return stk1.top();
	}
	int min() {
		return stk2.top();
	}
};