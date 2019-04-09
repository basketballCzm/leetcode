/*
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/

//用两个栈来模拟队列，push操作直接push进入stack1，pop首先pop stack2，当stack2 为空的时候将stack1中的内容移到stack2中，然后再对Sstack2进行出栈

class Solution {
  public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (!stack2.empty()) {
			int tmp = stack2.top();
			stack2.pop();
			return tmp;
		} else {
			while (!stack1.empty()) {
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		if (!stack2.empty()) {
			int tmp = stack2.top();
			stack2.pop();
			return tmp;
		}
		return -1;
	}

  private:
	stack<int> stack1;
	stack<int> stack2;
};