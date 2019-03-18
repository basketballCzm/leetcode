/*
给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"
*/
/*
相当于按照合并两个链表的思路进行合并两个二进制串，但是遍历的顺序要注意按照从尾到头的顺序进行遍历。可以使用string::reverse_iterator迭代器进行处理
注意使用
a.rbegin() string::reverse_iterator  
a.begin() string::iterator  
a.cbegin() string::const_iterator
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string c;
        int flag = 0;
        string::reverse_iterator ita = a.rbegin();
        string::reverse_iterator itb = b.rbegin();

        while(a.rend() != ita && b.rend() != itb){
            int tmp = (*ita-'0'+*itb-'0')+flag;
            if(3 == tmp){
                flag = 1;
                c.insert(c.begin(), '1');
            }else if(2 == tmp){
                flag = 1;
                c.insert(c.begin(), '0');
            }else if(1 == tmp){
                flag = 0;
                c.insert(c.begin(), '1');
            }else{
                flag = 0;
                c.insert(c.begin(), '0');
            }

            ita++;
            itb++;
        }

        while(a.rend() !=  ita){
            int tmp = (*ita-'0')+flag;
            if(2 == tmp){
                flag = 1;
                c.insert(c.begin(), '0');
            }else if(1 == tmp){
                flag = 0;
                c.insert(c.begin(), '1');
            }else{
                flag = 0;
                c.insert(c.begin(), '0');
            }

            ita++;
        }

        while(b.rend() !=  itb){
            int tmp = (*itb-'0')+flag;
            if(2 == tmp){
                flag = 1;
                c.insert(c.begin(), '0');
            }else if(1 == tmp){
                flag = 0;
                c.insert(c.begin(), '1');
            }else{
                flag = 0;
                c.insert(c.begin(), '0');
            }
            itb++;
        }

        if(1 == flag){
            c.insert(c.begin(), '1');
        }

        return c;

    }
};


class Solution {
public:
    string addBinary(string a, string b) {

        int alen = a.length(), blen = b.length();
        if (alen == 0) {
            return b;
        }
        if (blen == 0) {
            return a;
        }

        string result = "";
        int len = alen > blen ? alen : blen;
        int C = 0;

        for (int i = 1; i <= len; ++i) {
            int anum = alen - i >= 0 ? a[alen - i] - '0' : 0;
            int bnum = blen - i >= 0 ? b[blen - i] - '0' : 0;
            int ans = anum + bnum + C;
            int aans = ans % 2;
            C = ans / 2;
            char cans = '0' + aans;
            result = cans + result;
        }

        if (C == 1) {
            result = '1' + result;
        }

        return result;
    }
};