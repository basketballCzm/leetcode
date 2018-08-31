/*
给定一个长度为 n 的整数数组 A 。

假设 Bk 是数组 A 顺时针旋转 k 个位置后的数组，我们定义 A 的“旋转函数” F 为：

F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1]。

计算F(0), F(1), ..., F(n-1)中的最大值。

注意:
可以认为 n 的值小于 105。

示例:

A = [4, 3, 2, 6]

F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

所以 F(0), F(1), F(2), F(3) 中的最大值是 F(3) = 26 。
*/


/*
这道题是一道很巧妙的公式推断题目，直接写时间复杂度为O(n2),这样不能通过OJ的测试，推导公式后时间复杂度变为O(n)
{A,B,C,D}
F(0) = B+2C+3D
F(1) = A+2B+3C
F(2) = 2A+3B+D
F(3) = 3A+C+2D


递推公式 F(n) = F(n-1) + sum - n*A[n-i]

这道题前三次O(n2)

注意后面递推式的 n >= 2的情况
*/
#include <iostream>
#include <vector>
#include <cmatch>
/*
INT_MIN
INT_MAX
*/
class Solution {
public:

	int maxRotateFunction(vector<int>& A) {
		int sum = 0;
		int size = A.size();
		if(size <= 1){
			return 0;
		}
		int f_func = 0; 
		for(int i = 0; i < size; i++){
			sum += A[i];
			f_func += i*A[i];
		}

		int f_max = f_func;
		//mark
		for(int i = 1; i < size; i++){
			f_func = f_func + sum - size*A[size-i];
			if(f_max < f_func){
				f_max = f_func;
			}
		}

		return f_max;
	}

    int maxRotateFunction(std::vector<int>& A) {
    	int size = A.size();
    	if(0 == size){
    		return 0;
    	}

    	//将最大值设置为INT_MIN是一个好的习惯 climit
    	int Fmax = INT_MIN;
    	for(int i = 0; i < size; i++){
    		//首先进行旋转容器
    		/*std::vector<int> rotation_v = rotation_vector(i, A);
    		//然后进行得到F_function值
    		int sum = F_function(rotation_v);*/
    		//int sum = rotation_vector_F_function(i,A);
    		int sum = 0;
    		for(int j = 0; j < size; j++){
    			sum += ((j+i)%size)*A[j];
    		}
    		if(Fmax < sum){
    			Fmax = sum;
    		}
    	}
    	return Fmax;
    }



    int rotation_vector_F_function(int n, std::vector<int>& A){
    	int size = A.size();
    	int sum = 0;
    	int location = 0;
    	for(int i = 0; i < size; i++){
    		location = (i+n)%size;
    		sum += (location*A[i]);
    	}
    	return sum;
    }

    std::vector<int> rotation_vector(int n, std::vector<int>& A){
    	int size = A.size();
    	std::vector<int> tmp_v(size,0);
    	for(int i = 0; i < size; i++){
    		tmp_v[(i+n)%size] = A[i];
    	}
    	return tmp_v;
    }

    int F_function(std::vector<int>& A){
    	int cnt = 0;
    	int sum = 0;
    	for(auto num : A){
    		sum += cnt*num;
    		cnt++;
    	}
    	return sum;
    }
};

int main(){
	return 0;
}