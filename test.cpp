#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

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
    string s = "123";
    cout << s.insert(3,"4");
    if(s < "12345"){
        cout << "YES" << endl;
    }
    //std::cout << s.nthSuperUglyNumber(85,v) << std::endl;
}