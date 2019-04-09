class Solution {
  public:
    int Fibonacci(int n) {
        //return FibR(n);
        //return FibR(n, 0, 1);
        if (0 == n) {
            return 0;
        }
        vector<int> v(n, 1);
        for (int i = 2; i < n; i++) {
            v[i] = v[i - 1] + v[i - 2];
        }

        return v[n - 1];
    }

    int FibR1(int n) {
        if (1 == n || 2 == n) {
            return 1;
        }
        return FibR(n - 1) + FibR(n - 2);
    }

    //尾递归
    int FibR(int n, int num1, int num2) {
        if (0 == n) {
            return 0;
        }
        if (1 == n) {
            return num2;
        }
        return FibR(n - 1, num2, num1 + num2);
    }
};