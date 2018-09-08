/*
给定一个 32 位有符号整数，将整数中的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。
*/
/*
解题思路：1. 首先计算出该整数的位数，然后依次从低到高乘以整数位数从大到小。比如个位数乘以10的位数次方；然后依次位数加加，次方减减
2. sum = sum*10 + x%10;
   x = x/10;

   这样可以按照个位到最高位依次进行循环
*/

class Solution {
public:
    int reverse(int x) {
    	int flag = 0;
    	if(x < 0){
    		flag = 1;
    		x = -x;
    	}

    	unsigned long long  cnt = 0;
    	int tmp = x;
    	while(tmp/10){
    		cnt++;
    		tmp = tmp/10;
    	}
    	cnt++;

    	cnt = pow(10,cnt-1);
    	tmp = x;
    	//在这里sum计算第一位就已经溢出了  1534236469
    	unsigned long long sum = 0;
    	while(tmp/10){
    		sum += ((unsigned long long)(tmp%10))*cnt;
    		cnt = cnt/10;
    		tmp = tmp/10;
    	}

    	sum += (tmp%10)*cnt;

    	if(sum > pow(2,31)-1){
    		return 0;
    	}

    	return flag?-sum:sum;
    }

    int reverse(int x){
    	int flag = 0;
    	if(x < 0){
    		flag = 1;
    		x = -x;
    	}

    	//这里一定不能用int 因为在翻转的过程中该数就可能已经溢出
    	unsigned long long sum = 0;
    	while(x/10){
    		sum = sum*10 + (x%10);
    		x = x/10;
    	}
    	sum = sum*10+x%10;

    	//整数溢出判断
    	if(sum > (pow(2,31)-1)){
    		return 0;
    	}

    	return flag?-sum:sum;
    }


};