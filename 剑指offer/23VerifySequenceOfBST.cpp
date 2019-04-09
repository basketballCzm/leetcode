/*
首先判断原序列是否为后序，然后判断左右子树是否为后序序列
*/


class Solution {
  public:
    bool judge(vector<int>& s, int left, int right) {
        if (left >= right) {
            return true;
        }

        int mid = right - 1;
        while (s[mid] > s[right]) {mid--;}
        for (int i = mid; i >= left; i--) {
            if (s[i] > s[right]) {
                return false;
            }
        }

        return judge(s, left, mid) & judge(s, mid + 1, right - 1);
    }
    //这道题目的结束条件当时无法得出，其实思路还是蛮清楚
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (0 == sequence.size()) {
            return false;
        }

        return judge(sequence, 0, sequence.size() - 1);
    }
};