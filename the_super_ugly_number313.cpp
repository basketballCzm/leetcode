/*
编写一段程序来查找第 n 个超级丑数。

超级丑数是指其所有质因数都是长度为 k 的质数列表 primes 中的正整数。

示例:

输入: n = 12, primes = [2,7,13,19]
输出: 32 
解释: 给定长度为 4 的质数列表 primes = [2,7,13,19]，前 12 个超级丑数序列为：[1,2,4,7,8,13,14,16,19,26,28,32] 。
说明:

1 是任何给定 primes 的超级丑数。
 给定 primes 中的数字以升序排列。
0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000 。
第 n 个超级丑数确保在 32 位有符整数范围内。
*/

/*79 / 83 个通过测试用例  这种方法会超过时间限制，最后几个数据是比较大的数据 
思路：获取一个数的质因数，校验这些质因数是否在primes的集合中，如果在集合中就将该数加入丑数集合
*/
#include <iostream>
#include <cmath>
#include <vector>

class Solution {
public:
    int nthSuperUglyNumber(int n, std::vector<int>& primes) {
    	std::vector<long> uglyNum;
    	uglyNum.emplace_back(1);
    	if(1 == n){
    		return 1;
    	}
    	long max = pow(2,31)-1;
    	for(long i = 2; i < max; i++){
    		std::vector<int> primeFactors = getPrimefactor(i);
    		if(isUglyNum(primeFactors, primes)){
    			uglyNum.emplace_back(i);
    			if(uglyNum.size() == n){
    				return uglyNum[n-1];
    			}
    		}
    	}
    }

    bool isUglyNum(std::vector<int>& primeFactors, std::vector<int>& primes){
    	int flag = 0;
    	if(primeFactors.empty()){
    		return false;
    	}

    	for(auto primeFactor : primeFactors){
    		for(auto prime : primes){
    			if(primeFactor == prime){
    				flag++;
    				//mark continue;
    				break;
    			}
    		}
    	}

    	if(flag == primeFactors.size()){
    		return true;
    	}else{
    		return false;
    	}
    }

    std::vector<int> getPrimefactor(int n){
    	std::vector<int> res;
    	//因数包含1和本身，而质因子1般情况不包含1和本身
    	//res.emplace_back(1);
    	//mark 这里出错 1009 无质因数 在比较过成中当成了丑数
    	//mark 5045 = 5*1009 只存储5 right
    	for(int i = 2; i < 1000; i++){
    		while(n >= i){
    			if(n%i == 0){
    				res.emplace_back(i);
    				n /= i;
    			}else{
    				break; 
    			}
    		}
    	}

    	//mark 5045 = 5*1009 只存储5 right 去除这种情况
    	if(n > 1000){
    		res.clear();
    	}

    	return res;
    }
};

int main(){
	int a[30] = {5,17,19,23,47,53,59,61,67,71,73,89,101,107,109,113,131,149,157,163,167,179,181,191,199,211,223,233,239,251};
	std::vector<int> v;
	v.insert(v.begin(), a, a+30);

	Solution s;

	/*std::vector<int> tmp = s.getPrimefactor(5045);
	for(auto n:tmp){
		std::cout << n << std::endl;
	}*/
	std::cout << s.nthSuperUglyNumber(250,v) << std::endl;


	return 0;
}