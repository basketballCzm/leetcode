/*
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
    	vector<string> res;
    	int size = s.size();
    	//特别大的字符串直接去掉
    	if(size > 12){
    		return res;
    	}
    	for(int i = 1; i < size; i++){
    		for(int j = i+1; j < size; j++){
    			for(int k = j+1; k < size; k++){
    				string s_tmp = s;
    				s_tmp.insert(k,".");
    				s_tmp.insert(j,".");
    				s_tmp.insert(i,".");
    				if(checkIPAddress(s_tmp)){
    					res.emplace_back(s_tmp);
    				}
    			}
    		}
    	}
    	return res;
    }

    bool checkIPAddress(string s){
    	string s_num;
    	int size = s.size();
    	for(int i = 0; i < size; i++){
    		if('.' == s[i]){
    			//cout << s_num << endl;
    			if(stringtoi(s_num) <= stringtoi("255") && stringtoi(s_num) >= stringtoi("0")){
    				//["0.1.0.010","0.1.00.10","0.1.001.0","0.10.0.10","0.10.01.0","0.100.1.0","01.0.0.10","01.0.01.0","01.00.1.0","010.0.1.0"]
    				if(s_num[0] == '0' && s_num.size() > 1){
    					return false;
    				}
    				s_num = "";
    				continue;
    			}else{
    				return false;
    			}
    		}
    		s_num.insert(s_num.end(), s[i]);
    	}

    	//string的运算符重载只能比较相同大小的字符串
    	if(stringtoi(s_num) <= stringtoi("255") && stringtoi(s_num) >= stringtoi("0")){
    		if(s_num[0] == '0' && s_num.size() > 1){
    			return false;
    		}
    		return true;
    	}else{
    		return false;
    	}
    }

    int stringtoi(string s){
    	int size = s.size();
    	int sum = 0;
    	int cnt = 1;
    	for(int i = size-1; i >= 0; i--){
    		sum += cnt*(s[i] - '0');
    		cnt *= 10;
    	}

    	return sum;
    }
};

int main(){
	Solution s;
	
	vector<string> v_s = s.restoreIpAddresses("25525511135");
	for(auto tmp:v_s){
		cout << tmp << endl;
	}

	cout << s.checkIPAddress("255.255.111.35") << endl;;
	return 0;
}