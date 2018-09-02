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

class Solution {
public:
    string longestPalindrome(string s) {
    	int mid = 0;
    	int left = 0;
    	int right = 0;
    	int max_left = 0;
    	int max_right = 0;
    	int size = s.size();
    	for(int i = 0; i < size; i++){
    		mid = i;
    		for(int j = 1; j < size; j++){
    			left = mid - j;
    			right = mid + j;
    			while(left >= 0){
    				if(s[left] == s[mid]){
    					left--;
    					continue;
    				}
    			}
    			while(right < size){
    				if(s[right] == s[mid]){
    					right++;
    					continue;
    				}
    			}
    			if(left >= 0 && right <= size){
    				if(s[left] == s[right]){
    					if((right-left)>(max_right-max_left))
    					{
    						max_right = right;
    						max_left = left;
    					}
    				}
    			}
    		}
    	}
    }
};
