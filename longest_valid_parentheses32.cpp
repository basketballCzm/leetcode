/*
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"

*/

/*
这种方法 “()(()” 测试用例不能通过

可以使用栈的方法来匹配，首先'('入栈，遇到')',检查栈是否为空如果栈为空那么start = i+1,继续循环
如果栈不为空，那么首先出栈一个'('进行字符串匹配，如果此时栈不为空，那么取较大值i-top()，如果栈为空，那么
取较大值i-start+1
*/
class Solution {
public:
	//有时候想到双下标问题的时候，可以尝试使用一下栈或者队列这几种数据结构
    int longestValidParentheses(string s) {
    	int size = s.size();
    	int left = 0;
    	int right = 0;
    	int max = 0;
    	for(int i = 0; i < size; i++){
    		left = 0;
    		right = 0;
    		while(left >= right && i < size){
    			if('(' == s[i]){
    				left++;
    			}else if(')' == s[i]){
    				right++;
    			}
    			i++;
    		}
    		i--;
    		left = left>right?right:left;
    		max = max>left*2?max:left*2;
    	}

    	return max;
    }
};

class Solution{
public:
    int longestValidParentheses(string s){
        int size = s.size();
        int max = 0;
        int start = 0;
        stack<int> stk;
        for(int i = 0; i < size; i++){
            if('(' == s[i]){
                stk.push(i);
            }else if(')' == s[i]){
                if(!stk.empty()){
                    stk.pop();
                    if(!stk.empty()){
                        max = max>(i-stk.top())?max:(i-stk.top());
                    }else{
                        max = max>(i-start+1)?max:(i-start+1);
                    }
                }else{
                    start = i+1;
                }
            }
        }

        return max;
    }
};
