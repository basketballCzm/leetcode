/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶

思路：
1. 使用DFS进行搜索。
2. 使用非递归算法通过栈进行迭代
3. 动态规划方法，符合该网站的时间复杂度。
即本层楼梯上楼方法数和前两层楼梯的上楼方法数有关。

*/

//递归的方法会超出时间限制
class Solution {
  public:
    int climbStairs(int n) {
        if (n <= 0) {
            return 1;
        }

        int cnt = 0;
        climbStairsR(n, 0, cnt);
        return cnt;
    }

    void climbStairsR(int n, int step, int& cnt) {
        if (step > n) {
            return;
        } else if (step == n) {
            cnt++;
            return;
        } else {
            climbStairsR(n, step + 1, cnt);
            climbStairsR(n, step + 2, cnt);
        }
    }
};

//使用栈方法，即深度优先搜索的非递归算法
class Solution {
  public:
    int climbStairs(int n) {
        if (n <= 0) {
            return 1;
        }

        int cnt = 0;
        stack<int> stk;
        stk.push(1);
        stk.push(2);
        while (!stk.empty()) {
            int stp = stk.top();
            stk.pop();
            if (n == stp) {
                cnt++;
            } else if (stp < n) {
                stk.push(stp + 1);
                stk.push(stp + 2);
            }
        }

        return cnt;
    }
};

//使用队列。即广度优先搜索到额非递归算法
class Solution {
  public:
    int climbStairs(int n) {
        if (n <= 0) {
            return 1;
        }

        int cnt = 0;
        deque<int> deq;
        deq.push_back(1);
        deq.push_back(2);

        while (!deq.empty()) {
            int stp = deq.front();
            deq.pop_front();

            if (stp == n) {
                cnt++;
            } else if (stp < n) {
                deq.push_back(stp + 1);
                deq.push_back(stp + 2);
            }
        }

        return cnt;
    }
};


//动态规划方法
class Solution {
  public:
    int climbStairs(int n) {
        if (n <= 1) {
            return 1;
        }
        vector<int> v(n + 1, 0);
        v[1] = 1;
        v[2] = 2;
        for (int i = 3; i <= n; i++) {
            v[i] = v[i - 1] + v[i - 2];
        }

        return v[n];
    }
};
