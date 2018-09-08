/*
将字符串 "PAYPALISHIRING" 以Z字形排列成给定的行数：

P   A   H   N
A P L S I I G
Y   I   R
之后从左往右，逐行读取字符："PAHNAPLSIIGYIR"

实现一个将字符串进行指定行数变换的函数:

string convert(string s, int numRows);
示例 1:

输入: s = "PAYPALISHIRING", numRows = 3
输出: "PAHNAPLSIIGYIR"
示例 2:

输入: s = "PAYPALISHIRING", numRows = 4
输出: "PINALSIGYAHRPI"
解释:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

/*
解题思路：r 表示当前行数 R 表示总行数 I(n)表示第n个字符在原来字符串中的下标
r = 0 && R-1: I(n+1) = I(n)+2*(R-1)
0 < r < R: 
当n = 奇数： I(n+1) = I(n)+2*(R-r-1)
当n = 偶数： I(n+1) = I(n-1)+2*(R-1)     I(n) + 2*(r)


这道题目主要就是找到数字之间的变化规律，在查找规律时可以使用数字下标先找到各个数之间的关系，再进行求解
*/

class Solution {
public:
    string convert(string s, int numRows) {
    	string res;
    	int count = 0;
    	int size = s.size();
    	if(numRows == 1){
    		return s;
    	}
    	//第一行
    	for(int i = 0; i < size; i += 2*(numRows-1)){
    		res.insert(res.end(),s[i]); 
    	}


    	for(int i = 1; i < numRows-1; i++){
    		for(int j = i, flag = 1; j < size; flag++){
    			res.insert(res.end(), s[j]);
    			if(flag%2){
    				j += 2*(numRows-i-1);
    			}else{
    				j += 2*i;
    			}
    		}
    	}

    	//最后一行
    	for(int i = numRows-1; i < size; i += 2*(numRows-1)){
    		res.insert(res.end(), s[i])
    	}

    	return res;
    }
};