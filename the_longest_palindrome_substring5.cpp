/*

给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba"也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

*/
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
    	int left = 0;
    	int right = 0;
    	int max_left = 0;
    	int max_right = 0;
    	int size = s.size();

    	//暴力搜索法
    	for(int i = 0; i < size; i++){ //起始地址
    		for(int j = i+1; j < size; j++){ //结束地址
    			int tmp1 = i;
    			int tmp2 = j;
    			for(tmp1 = i, tmp2 = j; tmp2 >= tmp1; tmp2--, tmp1++){
    				if(s[tmp1] != s[tmp2]){
    					break;
    				}
    			}
    			if((tmp1 >= tmp2) && (j-i) > (max_right-max_left)){
    					max_right = j;
    					max_left = i;
    			}
    		}
    	}

    	//substr(起始位子，起始位子和后面几位(包含起始位子))
    	return s.substr( max_left, max_right-max_left+1 );
    	//奇数和偶数分开进行讨论
    	//回文数为奇数的情况
    }


    // 从中间向两边进行搜索，分回文数为奇数或者回文数为偶数的情况进行分类
    string longestPalindrome(string s) {
        int max_left = 0;
        int max_right = 0;
        int left = 0;
        int right = 0;
        int size = s.size();

        //当回文数为奇数
        for(int i = 0; i < size; i++){
            left = i-1;
            right = i+1;
            while(left >= 0 && right < size){
                if(s[left] == s[right]){
                    if((right-left) > (max_right-max_left)){
                        max_right = right;
                        max_left = left;
                    }
                }else{
                    break;
                }
                left--;
                right++;
            }
        }

        for(int i = 0; i < size; i++){
            left = i;
            right = i+1;
            while(left >= 0 && right < size){
                if(s[left] == s[right]){
                    if((right-left) > (max_right-max_left)){
                        max_right = right;
                        max_left = left;
                    }
                }else{
                    break;
                }
                left--;
                right++;
            }
        }

        return s.substr(max_left,max_right-max_left+1);
        //当回文数为奇数
    }

    //动态规划解法
    /*
    解题思路：
    字符串为s, f(i,j)表示最长的回文子序列
    当 i > j 时f(i,j) = 0;
    i = j  f(i,j) = 1;
    i < j && s[i] == s[j] 时 f(i,j) = f(i+1,j-1)+2
    i < j && s[i] != s[j] 时 f(i,j) = max(f(i+1,j) , f(i,j-1))

    计算dp[i][j]时需要计算dp[i+1][*]或dp[*][j-1]，因此i应该从大到小，即递减；j应该从小到大，即递增。
    */
    string longestPalindrome(string s) {
        int dp[1001][1001] = {0};
        int size = s.size();
        for(int i = size-1; i < size; i--){
            dp[i][i] = 1;
            for(int j = i+1; j < size; j++){
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1] +2;
                }else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }

        return dp[0][size-1];

    }

};

int main(){
    Solution s;
    string l = s.longestPalindrome1("aaaaaa");
    cout << l << endl;
    return 0;
}

/*
command=`echo /opt/local/bin/eosiocpp  -emit-llvm -O3 --std=c++14 --target=wasm32 -nostdinc \
                                   -nostdlib -nostdlibinc -ffreestanding -nostdlib -fno-threadsafe-statics -fno-rtti \
                                   -fno-exceptions -I ${EOSIO_INSTALL_DIR}/include \
                                   -I${EOSIO_INSTALL_DIR}/include/libc++/upstream/include \
                                   -I${EOSIO_INSTALL_DIR}/include/musl/upstream/include \
                                   -I${BOOST_INCLUDE_DIR} \
                                   -I $filePath \
                                   -c $file -o $workdir/built/$name`
/opt/local/include/eosiolib/dispatcher.hpp
*/