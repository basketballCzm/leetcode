/*
我们把符合下列属性的数组 A 称作山脉：

A.length >= 3
存在 0 < i < A.length - 1 使得A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
给定一个确定为山脉的数组，返回任何满足 A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1] 的 i 的值。

 

示例 1：

输入：[0,1,0]
输出：1
示例 2：

输入：[0,2,1,0]
输出：1
 

提示：

3 <= A.length <= 10000
0 <= A[i] <= 10^6
A 是如上定义的山脉
*/

/*
解题思路： 这种方法是从中间向两边递推，还有一种方法是找到第一个递减的位置即为峰顶i   A[i] < A[i-1]
*/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
    	int size = A.size();
    	int left = 0;
    	int right = 0;
    	int flag = 0;
    	int i = 0;
    	for(i = 0; i < size; i++){
    		flag = 0;
    		for(left = i-1; left >= 0; left--){
    			if(A[left] >= A[i] ){
    				flag = 1;
    				break;
    			}
    		}

    		if(flag){
    			continue;
    		}

    		for(right = i+1; right < size; right++){
    			if(A[right] >= A[i]){
    				flag = 1;
    				break;
    			}
    		}

    		if(flag){
    			continue;
    		}

    		break;
    	}

    	return i;
    }
};