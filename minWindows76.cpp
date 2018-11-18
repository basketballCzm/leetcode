/*
给定一个字符串 S 和一个字符串 T，请在 S 中找出包含 T 所有字母的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：

如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。
*/

#include <iostream>
#include <string>
using namespace std;


//超出时间限制
/*
解题思路：两层for循环，选出所有可能字符串，然后对于所有字符串进行检查操作。注意检查操作时区分‘bba’和‘abb’的情况。

小型hash表+遍历字符串的一层for循环方法(滑动窗口方法)
将目标字符串映射为一个大小为255的小型hash表，然后遍历原字符串，用i值进行滑动，用start值进行固定，一次匹配完成后注意在选取最小子串的时候进行字符串开始start阶段的去重工作，完成后与前一个子串大小相互比较，然后再将start++，found--。注意在操作start值的时候对应的shash的值也要做相应的变化
*/
class Solution {
public:
    string minWindow(string s, string t) {
    	string res;
    	int s1 = s.size();
    	int t1 = t.size();
    	if(s1 < t1){
    		return "";
    	}

    	for(int i = 0; i < s1; i++){
    		//mark  这里的s1要加1
    		for(int j = i+t1; j < s1+1; j++){
    			string tmp = s.substr(i,j-i);
    			if(check_substr(t,tmp)){
    				if(res.empty()){
    					res = tmp;
    				}else{
    					if(tmp.size() < res.size()){
    						res = tmp;
    					}
    				}
    				break;
    			}
    		}
    	}

    	return res;
    }

    bool check_substr(string t, string sub_str){

    	int size1 = t.size();
    	int size2 = sub_str.size();
    	int ncount = 0;
    	for(int i = 0; i < size1; i++){
    		for(int j = 0; j < size2; j++){
    			if(t[i] == sub_str[j]){
    				ncount++;
    				/*
 输入：
"bbaa"
"aba"
输出：
"bba"
预期：
"baa"
    				*/
    				sub_str.erase(sub_str.begin()+j, sub_str.begin()+j+1);
    				break;
    			}
    		}
    	}
    	if(ncount == size1){
    		return true;
    	}else{
    		return false;
    	}
    }
};

int main(){
	Solution s;
	string s1 = s.minWindow("a","a");
	string s2 = "0123456";
	s2.erase(s2.begin(),s2.begin()+1);
	cout << s2 << endl;
}


class Solution{
public:
	string minWindow(string s, string t){
		if(s.empty() || t.empty()){
			return "";
		}
		int shash[255] = {0};
		int thash[255] = {0};
		for(int i = 0; i < t.size(); i++){
			thash[t[i]]++;
		}

		int start = 0;
		int res = s.size()+1;
		int res_start = -1;
		int res_end = 0;
		int found = 0;
		for(int i = 0, start = i; i < s.size(); i++){
			shash[s[i]]++;

			if(shash[s[i]] <= thash[s[i]]){
				found++;
			}

			if(found == t.size()){
				//去除字符串开头多余的字符
				while(start < i && shash[s[start]] > thash[s[start]]){
					shash[s[start]]--;
					start++;
				}

				if(i-start+1 < res){
					res_start = start;
					res_end = i;
					res = i-start+1;
				}

				//将开始字符向前重新移动一个
				shash[s[start]]--;
				start++;
				found--;
			}
		}

		if(-1 == res_start){
			return "";
		}

		return s.substr(res_start, res);
	}
};