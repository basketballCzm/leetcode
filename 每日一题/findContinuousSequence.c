/*
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

 

示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
 

限制：

1 <= target <= 10^5


每个数目的连续序列只可能存在一个，找到一个基准点，然后校验以改基准点的序列是否符合要求
*/
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        for(int cnt = 2, first = (target-1)/2; first >= 1; cnt++, first = (target-getsum(cnt))/cnt){
            vector<int> tmp;
            int sum = 0;
            for(int i = 0; i < cnt; i++){
                sum += (first+i);
                tmp.push_back(first+i);
            }
            //
            //printf("cnt:%d\n", cnt);
            if(sum == target){
                res.push_back(tmp);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }

    int getsum(int cnt){
        int sum = 0;
        for(int i = 0; i < cnt; i++){
            sum += i;
        }
        return sum;
    }
};