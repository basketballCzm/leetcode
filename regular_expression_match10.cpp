/*
给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符。
'*' 匹配零个或多个前面的元素。
匹配应该覆盖整个字符串 (s) ，而不是部分字符串。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:

输入:
s = "aa"
p = "a*"
输出: true
解释: '*' 代表可匹配零个或多个前面的元素, 即可以匹配 'a' 。因此, 重复 'a' 一次, 字符串可变为 "aa"。
示例 3:

输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个('*')任意字符('.')。
示例 4:

输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 'c' 可以不被重复, 'a' 可以被重复一次。因此可以匹配字符串 "aab"。
示例 5:

输入:
s = "mississippi"
p = "mis*is*p*."
输出: false
*/

/*
解题思路: 首先辨别两种情况，
当p为'*'：
检查p'*'之前的字符是否和s当前的字符相同如果相同s的index--match
*/
#include <iostream>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
    	return Match(s, s.size()-1, p, p.size()-1);
    }

    bool Match(string s, int s_index, string p, int p_index){
    	if(s_index == -1 && p_index == -1){
    		return true;
    	}
    	if('*' == p[p_index]){
    		if(s_index < 0){
    			return Match(s, s_index, p, p_index-2);
    		}
    		if(p[p_index-1] == s[s_index]){
    			return Match(s, s_index-1, p, p_index);
    			/*  "ab"   ".*c"  */
    		}else if('.' == p[p_index-1]){
    			//p[p_index-1] = s[s_index];
    			return true;
    			//"**"
    		}else if('*' == p[p_index-1]){
    			return Match(s, s_index, p, p_index-1);
    		}else{
    			return Match(s, s_index, p, p_index-2);
    		}
    	}else if('.' == p[p_index]){
    		return Match(s, s_index-1, p, p_index-1);
    	}else if(p[p_index] != s[s_index]){
    		return false;
    	}else{
    		return Match(s, s_index-1, p, p_index-1);
    	}
    }
};

int main(){
	Solution s;
	cout << s.isMatch("aa","a*") << endl;
	return 0;
}