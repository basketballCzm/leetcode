#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

class Solution {
public:
    std::vector<int> nthSuperUglyNumber(int n, std::vector<int>& primes) {  
        int len = primes.size();  
        std::vector<int> index(len, 0);
        std::vector<int> uglyNum(n, INT32_MAX);
        std::vector<int> temp(len);
        uglyNum[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            int minj = -1;
            int minNum = INT32_MAX;

            for (int j = 0; j < len; ++j)
            {
                temp[j] = primes[j] * uglyNum[index[j]];
                if (temp[j] < uglyNum[i])
                {
                    minNum = temp[j];
                    uglyNum[i] = temp[j];
                    minj = j;
                }
            }
            for (int j = minj; j < len; ++j)
            {
                if (minNum == temp[j])
                ++index[j];
            }
        }
        return uglyNum;
    }


};


int main(){
    int a[30] = {5,17,19,23,47,53,59,61,67,71,73,89,101,107,109,113,131,149,157,163,167,179,181,191,199,211,223,233,239,251};
    std::vector<int> v;
    v.insert(v.begin(), a, a+30);

    Solution s;

    std::vector<int> tmp = s.nthSuperUglyNumber(250,v);
    //std::vector<int> tmp = s.getPrimefactor(1009);
    for(auto n:tmp){
        std::cout << n << std::endl;
    }
    //std::cout << s.nthSuperUglyNumber(85,v) << std::endl;
}