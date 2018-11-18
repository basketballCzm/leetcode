/*
给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

说明：

给定 n 的范围是 [1, 9]。
给定 k 的范围是[1,  n!]。
示例 1:

输入: n = 3, k = 3
输出: "213"
示例 2:

输入: n = 4, k = 9
输出: "2314"
*/

//这种DFS的模板要记住，注意与算法分析3.2实验相对比，3.2实验DFS写法成立的原因是在DFS函数中不存在循环，只是判断true和false，然而这里是需要把循环结束的值加入到结果的集合中。这样会造成一个结果重复多次。下面的模板将visited写在外面能防止这种情况。

//这一道题目要求了时间复杂度，普通的递归算法不能解决，需要用到非递归写法。

//新颖解法：康托展开式(数学解法)
/*
X=an*(n-1)!+an-1*(n-2)!+...+ai*(i-1)!+...+a2*1!+a1*0!

ai为整数，并且0<=ai<i(1<=i<=n)
*/
class Solution {
public:
    //DFS  取n的全排列的第k个
    string getPermutation(int n, int k) {
        vector<string> res;
        string str;
        vector<bool> visited(n+1, false);
        for(int i = 1; i <= n; i++){
            //起点步数为空，但是元素值str不为空
            visited[i] = true;
            DFS(n, visited, res, str+(char)(i+'0'));
            visited[i] = false;
        }

        if(k >= res.size()){
            return string();
        }

        return res[k-1];
    }

    void DFS(int n, vector<bool>& visited, vector<string>& res, string str){
        //结束条件
        if(n == str.size()){
            res.push_back(str);
            return;
        }else{
            for(int i = 1; i <= n; i++){
                if(!visited[i]){
                    visited[i] = true;
                    DFS(n, visited, res, str+(char)(i+'0'));
                    visited[i] = false;
                }
            }
        }

        return ;
    }
};

//康托法，在写编程题目时有时遇到一些简单的数学问题因该尝试用数学方法进行求解
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        if(k <= 0 || n <= 0){
            return res;
        }
        vector<int> vnum;
        for(int i = 0; i < n; i++){
            vnum.push_back(i+1);
        }

        k--;
        while(0 != n){
            int tmp = k/factor(n-1);
            res.insert(res.end(), vnum[tmp]+'0');
            //删除单个元素，删除一个区间值[0,3)删除前面3个元素
            vnum.erase(vnum.begin()+tmp);
            k = k%factor(n-1);
            n--;
        }

        return res;
    }

    int factor(int n){
        int sum = 1;
        for(int i = 1; i <= n; i++){
            sum *= i;
        }
        return sum;
    }
};

