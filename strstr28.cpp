/*
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
*/

/*
用两个下标同时来遍历haystack来记录其每一个子序列，与needle比较

haystack.find(needle);

haystack.substr(i,len);
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
    	if(needle.empty()){
    		return 0;
    	}
    	int size1 = haystack.size();
    	int size2 = needle.size();

    	int end = 0;
    	//0 --- size1-size2+1   来减小遍历的序列
    	for(int i = 0; i < size1-size2+1; i++){
    		int j = i;
    		for(j = i; j-i < size2; j++){
    			if(haystack[j] != needle[j-i]){
    				break;
    			}
    		}

    		if(j-i == size2){
    			return i;
    		}
    	}

    	return -1;
    }
};