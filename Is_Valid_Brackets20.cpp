/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true
*/
/*
解题思路：与上一题类似使用stack,如果为'('则入栈，如果')'首先判断栈是否为空，如果为空直接返回false，如果不为空，出栈查看栈顶元素和当前
括号对是否相互匹配，如果相互匹配则继续进行循环，否则返回false。
*/

class Solution {
public:
    bool isValid(string s) {
    	int size = s.size();
    	stack<char> stk;
    	for(int i = 0; i < size; i++){
    		if('(' == s[i] || '{' == s[i] || '[' == s[i]){
    			stk.push(s[i]);
    		}else if(')' == s[i] || '}' == s[i] || ']' == s[i]){
    			if(!stk.empty()){
    				char ch = stk.top();
    				if((')' == s[i] && '(' == ch) ||
    				   ('}' == s[i] && '{' == ch) ||
    				   (']' == s[i] && '[' == ch)){
    				   	stk.pop();
    				}else{
    					return false;
    				}
    			}else{
    				return false;
    			}
    		}
    	}

    	//栈不为空也返回为空
    	if(!stk.empty()){
    		return false;
    	}

    	return true;
    }
};