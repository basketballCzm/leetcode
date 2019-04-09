
class Solution {
  public:
    bool Find(int target, vector<vector<int>> array) {
        if (0 == array.size()) {
            return false;
        }

        int row = array.size();
        int col = array[0].size();

        //确定行
        for (int i = 0; i < row; i++) {
            if (i + 1 < row && array[i][0] <= target && array[i + 1][0] > target) {
                return findrow(target, array, i);
            } else if (i == row - 1) {
                return findrow(target, array, i);
            }
        }

        return false;
    }

    bool findrow(int target, vector<vector<int> > array, int row) {
        int col = array[0].size();

        for (int i = 0; i < col; i++) {
            if (array[row][i] == target) {
                return true;
            }
        }

        return false;
    }
};


class Solution {
  public:
    bool Find(int target, vector<vector<int> > array) {
        if (0 == array.size()) {
            return false;
        }

        return FindR(0, 0, target, array);
    }

    bool FindR(int x, int y, int target, vector<vector<int> > array) {
        int row = array.size();
        int col = array[0].size();
        if (x < row && y < col) {
            if (target == array[x][y]) {
                return true;
            } else {
                if (array[x + 1][y] <  target && array[x][y + 1] < target) {
                    return FindR(x + 1, y, target, array) || FindR(x, y + 1, target, array);
                } else if (array[x + 1][y] <= target) {
                    return FindR(x + 1, y, target, array);
                } else if (array[x][y + 1] <= target) {
                    return FindR(x, y + 1, target, array);
                } else {
                    return false;
                }
            }
        }

        return false;
    }

};


class Solution {
  public:
    struct point {
        int x;
        int y;
        point(int xx, int yy) {
            x = xx;
            y = yy;
        }
    };
    //使用搜索的非递归算法
    bool Find(int target, vector<vector<int> > array) {
        if (0 == array.size()) {
            return false;
        }

        int row = array.size();
        int col = array[0].size();

        stack<point> stk;
        stk.push(point(0, 0));
        while (!stk.empty()) {
            point tmp = stk.top();
            stk.pop();
            if (array[tmp.x][tmp.y] == target) {
                return true;
            }

            if (tmp.x + 1 < row && array[tmp.x + 1][tmp.y] <= target) {
                stk.push(point(tmp.x + 1, tmp.y));
            }

            if (tmp.y + 1 < col && array[tmp.x][tmp.y + 1] <= target) {
                stk.push(point(tmp.x, tmp.y + 1));
            }
        }

        return false;

    }
};