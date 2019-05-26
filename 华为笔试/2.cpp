#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

//abc3((3(A)B)B)abc
//解题思路：使用一个栈将数字和括号分别进行入栈，遇到回括号进行出栈，注意tmp字符串重复遍历的位置，当z栈为空时，将tmp字符串添加到res字符串的后面
int main() {
    string s;
    cin >> s;
    string res;
    stack<char> stk1; //number operator
    string tmp;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            stk1.push(s[i]);
        } else if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stk1.push(s[i]);
        } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            char ch = stk1.top();
            stk1.pop();
            if ((s[i] == ')' && ch == '(') || (s[i] == ']' && ch == '[') || (s[i] == '}' && ch == '{')) {
                if (!stk1.empty()) {
                    char ch = stk1.top();
                    if (ch >= '0' && ch <= '9') {
                        stk1.pop();
                        int index = ch - '0';
                        string tmp1 = tmp;
                        for (int i = 0; i < index - 1; i++) {
                            tmp.insert(tmp.end(), tmp1.begin(), tmp1.end());
                        }

                        //tmp.erase();
                    }
                }
            } else {
                return 0;
            }
        } else {
            if (!stk1.empty()) {
                tmp.insert(tmp.end(), s[i]);
            } else {

                if (!tmp.empty()) {
                    res.insert(res.end(), tmp.begin(), tmp.end());
                    tmp.erase();
                }

                res.insert(res.end(), s[i]);
            }
        }
    }

    if (!tmp.empty()) {
        res.insert(res.end(), tmp.begin(), tmp.end());
        tmp.erase();
    }

    cout << res << endl;
    return 0;
}