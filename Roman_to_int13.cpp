/*
罗马数字包含以下七种字符：I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

示例 1:

输入: "III"
输出: 3
示例 2:

输入: "IV"
输出: 4
示例 3:

输入: "IX"
输出: 9
示例 4:

输入: "LVIII"
输出: 58
解释: C = 100, L = 50, XXX = 30, III = 3.
示例 5:

输入: "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.
*/

/*
解题思路：字符串处理题目要分清各种情况的处理逻辑即可，
当 s[i] < s[i+1]  sum += s[i+1]-s[i]
当 s[i] = s[i+1]  sum += s[i]*cnt
当 s[i] > s[i+1]  sum += s[i]

注意：最后检查s[size-1]的时候不需要往后看一位，直接
sum += s[i]
*/

class Solution {
public:
	struct str_map{
		char ch;
		int num;
	};
	const str_map roman_to_int_map[8] = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000},{'#',0}};
    int romanToInt(string s) {
    	int size =  s.size();
    	int index = 0;
    	int sum = 0;
    	for(int i = 0; i < size; i++){
    		int index = i+1;
    		if(index == size){
    			sum += get_num(s[i]);
    			return sum;
    		}
    		if(get_num(s[i]) < get_num(s[index])){
    			sum += get_num(s[index]) - get_num(s[i]);
    			i++;
    		}else if(get_num(s[i]) == get_num(s[index])){
    			int count = 1;
    			while(i+1 < size && s[i+1] == s[i]){
    				i++;
    				count++;
    			}
    			sum += count*get_num(s[i-1]);
    		}else{
    			sum += get_num(s[i]);
    		}
    	}
    	
    	return sum;
    }

    int get_num(char ch){
    	int cnt = 0;
    	while('#' != roman_to_int_map[cnt].ch){
    		if(ch == roman_to_int_map[cnt].ch){
    			return roman_to_int_map[cnt].num ;
    		}
    		cnt++;
    	}

    	return -1;
    }
};