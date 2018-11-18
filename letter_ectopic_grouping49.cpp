/*
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	vector<vector<string>> res;
    	unordered_map<string, vector<string>> res_map;
    	for(int i = 0; i < strs.size(); i++){
    		string tmp = sortstr(strs[i]);
    		//sort(strs[i].begin(), strs[i].end());
    		res_map[strs[i]].push_back(tmp)
    	}

    	//迭代器就相当于一个指针，需要使用->
    	for(auto m:res_map){
    		res.push_back(m.second);
    	}

    	return res;
    }

    string sortstr(string& s){
    	string res;
    	int a[26] = {0};
    	for(auto ch:s){
    		a[ch-'a']++;
    	}

    	for(int i = 0; i < 26; i++){
    		for(int j = 0; j < a[i]; j++){
    			res.insert(res.end(),i+'a');
    		}
    	}

    	return res;
    }
};

int main(){
	Solution s;
	vector<string> strs;
	strs.push_back("hello");
	strs.push_back("cba");
	s.groupAnagrams(strs);
	return 0;
}