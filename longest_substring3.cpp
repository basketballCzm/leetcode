/*
给定一个字符串，找出不含有重复字符的最长子串的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 无重复字符的最长子串是 "abc"，其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 无重复字符的最长子串是 "b"，其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 无重复字符的最长子串是 "wke"，其长度为 3。
     请注意，答案必须是一个子串，"pwke" 是一个子序列 而不是子串。
*/

/*
解题思路：这道题的解题思路比较简单用两对记录值记录相应的最大区间和当前区间即可，但是要考虑全所有的情况
         当区间为0,1 和全部为最大区间这三种情况
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int size = s.size();
    	if(1 == size){
    		return 1;
    	}
    	int max_start = 0;
    	int max_last = 0;
    	int start = 0;
    	int last = 0;
    	for(last = 0; last < size; last++){
    		for(int i = start; i < last; i++){
    			if(s[i] == s[last]){
    				if(last-start > max_last-max_start){
    					max_start = start;
    					max_last = last;
    				}
    				start = i+1;
    				break;
    			}
    		}
    	}

    	return max_last-max_start > last-start ? max_last-max_start : last-start;
    }
};