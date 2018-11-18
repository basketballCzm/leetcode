/*
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。
*/
/*
明白二分查找的含义，left和right下标中，left下标表示二分查找中查找结束时该值要插入的位置，right表示left-1，即插入位置减1
注意事项:
1. 直接使用mid*mid，当mid为特别大的整数时会发生整数溢出(long long 可以避免发生整数溢出)
2. 在使用x/mid时注意mid为0的情况。

3. 其实在后面一题中使用mid*mid可以减小运算的时间
*/

class Solution {
public:
    int mySqrt(int x) {
    	if(0 == x || 1 == x){
    		return x;
    	}
    	int left = 0;
    	int right = x;
    	int mid = (left+right)/2;
    	while(left <= right){
    		//直接使用mid*mid会发生整数溢出
    		mid = (left+right)/2;
    		//注意尽管这里通过了测试，但是这里除出来是一个整数example:5
    		if(mid == x/mid){
    			return mid;
    		}else if(mid < x/mid){
    			left = mid+1;
    		}else{
    			right = mid-1;
    		}
    	}

    	//return left-1;
    	return right;
    }
};

//牛顿迭代法
/*
class Solution {
public:
    int mySqrt(int x) {
        long res = x;
        while (res * res > x) {
            res = (res + x / res) / 2;
        }
        return res;
    }
};
*/


//int end = min(num / 2, 46340);
//其实下面用mid*mid好一点，但是要确保结果不会发生整数溢出
class Solution {
public:
    bool isPerfectSquare(int num) {
    	if(1 == num){
    		return true;
    	}else if(0 == num){
    		return false;
    	}
    	int left = 0;
    	int right = num;
    	int mid = (left+right)/2;
    	while(left <= right){
    		//直接使用mid*mid会发生整数溢出
    		mid = (left+right)/2;
    		if(mid == (float)num/(float)mid){
    			return true;
    		}else if(mid < (float)num/(float)mid){
    			left = mid+1;
    		}else{
    			right = mid-1;
    		}
    	}

    	//return left-1;
    	return false;
        
    }
};
