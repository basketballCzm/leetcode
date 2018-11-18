/*

给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
     
class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	string s;
    	s.insert(s.end(), '(');
    	vector<string> res;
    	beginGenerate(res, s, n);
    	return res;
    }

    
    void beginGenerate(vector<string>& res, string s, int n){
    	//cout << s.size() << endl;
    	if(s.size() >= 2*n){
    		if(checkS(s)){
    			res.push_back(s);
    		}
    		return;
    	}

    	beginGenerate(res,s+'(',n);
    	beginGenerate(res,s+')',n);
    }

    bool checkS(string s){
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
        
        if(!stk.empty()){
            return false;
        }
        
        return true;
    }

};

int main(){
	Solution s;
	vector<string> res = s.generateParenthesis(3);
	for(auto s1 : res){
		cout << s1 << endl;
	}
	return 0;
}