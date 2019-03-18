/*
给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。

如果不存在最后一个单词，请返回 0 。

说明：一个单词是指由字母组成，但不包含任何空格的字符串。

示例:

输入: "Hello World"
输出: 5

思路：注意最后"a "这种情况下，最后一个单词的长度为1
*/
class Solution {
  public:
	int lengthOfLastWord(string s) {
		int len = s.size() - 1;
		int cnt = 0;
		while (' ' == s[len]) {
			len--;
		}
		while (len >= 0 && ' ' != s[len]) {
			cnt++;
			len--;
		}

		return cnt;

	}
};
