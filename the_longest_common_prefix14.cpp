/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。

*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	string str;
    	int size = strs.size();
    	if(0 == size){
    		return str;
    	}
    	int size1= strs[0].size();
    	int flag = 0;
    	//第一行为基准
    	for(int i = 0; i < size1; i++){
    		flag = 0;
    		//以第一个之后的字符串相互比较
    		for(int j = 1; j < size; j++){
    			if(strs[0][i] != strs[j][i]){
    				flag = 1;
    				break;
    			}
    		}

    		if(1 == flag){
    			return str;
    		}
    		str.insert(str.end(),strs[0][i]);
    	}
    	return str;
    }
};

cmake -DLLVM_CONFIG_BINARY=/usr/lib/llvm-4.0/bin/llvm-config -DLLVMCC=/usr/bin/clang-4.0 -DLLVMCXX=/usr/bin/clang++-4.0 \
-DENABLE_SOLVER_STP=ON \
../klee \
