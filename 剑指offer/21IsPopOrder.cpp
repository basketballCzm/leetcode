/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

*/

class Solution {
  public:
    //两个栈来实现  这里会有问题， 1,2,3,4,5    3,5,4,2,1 这里使用两个栈依旧会返回false
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        if (pushV.size() != popV.size()) {
            return false;
        }
        stack<int> stk1;
        stack<int> stk2;

        for (auto x : pushV) {
            stk1.push(x);
        }

        int flag = 0;
        for (auto x : popV) {
            if (!stk1.empty() && stk2.empty()) {
                while (!stk1.empty()) {
                    if (stk1.top() != x) {
                        stk2.push(stk1.top());
                        stk1.pop();
                    } else {
                        flag = 1;
                        stk1.pop();
                        break;
                    }
                }
            } else if (!stk1.empty() && !stk2.empty()) {
                if (stk1.top() == x) {
                    stk1.pop();
                    flag = 1;
                } else if (stk2.top() == x) {
                    stk2.pop();
                    flag = 1;
                }
            } else if (stk1.empty() && !stk2.empty()) {
                if (stk2.top() == x) {
                    stk2.pop();
                    flag = 1;
                }
            }

            if (0 == flag) {
                return false;
            }
            flag = 0;
        }

        return true;
    }
};



class Solution {
  public:
    //正确解法是使用一各辅助栈来模拟进栈和出栈的顺序
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        if (pushV.size() != popV.size()) {
            return false;
        } else if (0 == pushV.size()) {
            return false;
        }

        stack<int> stk;
        //两个指针，一个指针pushV 一个指针popV
        for (int i = 0, j = 0; i < pushV.size(); i++) {
            stk.push(pushV[i]);
            while (j < popV.size() && stk.top() == popV[j]) {
                stk.pop();
                j++;
            }
        }

        return stk.empty();


    }
};