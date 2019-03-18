/*以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。

在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径

请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。最后一个目录名（如果存在）不能以 / 结尾。此外，规范路径必须是表示绝对路径的最短字符串。



示例 1：

输入："/home/"
输出："/home"
解释：注意，最后一个目录名后面没有斜杠。
示例 2：

输入："/../"
输出："/"
解释：从根目录向上一级是不可行的，因为根是你可以到达的最高级。
示例 3：

输入："/home//foo/"
输出："/home/foo"
解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。
示例 4：

输入："/a/./b/../../c/"
输出："/c"
示例 5：

输入："/a/../../b/../c//.//"
输出："/c"
示例 6：

输入："/a//b////c/d//././/.."
输出："/a/b/c"

思路：那么我们可以把路径看做是由一个或多个"/"分割开的众多子字符串，把它们分别提取出来一一处理即可。
‘..’ 对string进行出栈(可以使用vector模拟栈)
‘.’  不作任何处理
不是上面的任意一个就进栈。
*/

//   "/..." 这个测试用例不能通过
class Solution {
  public:
    string simplifyPath(string path) {
        int size = path.size();
        string res;
        for (int i = 0; i < size;) {
            if (path[i] == '/' && path[i + 1] >= 'a' && path[i + 1] <= 'z') {
                res.insert(res.end(), path[i]);
                while (path[++i] != '/') {
                    if (i >= size) {
                        break;
                    }
                    res.insert(res.end(), path[i]);
                }
            } else if (path[i] == '/' && path[i + 1] == '/') {
                while ('/' == path[i + 1]) {
                    if (i >= size) {
                        break;
                    }
                    i++;
                }
            } else if (path[i] == '/' && path[i + 1] == '.' && path[i + 2] != '.') {
                i++;
                i++;
            } else if (path[i] == '/' && path[i + 1] == '.' && path[i + 2] == '.') {
                i++;
                i++;
                i++;
                if (!res.empty()) {
                    int cnt = res.size();
                    while (res[--cnt] != '/');
                    res.erase(res.begin() + cnt, res.end());
                }
            } else {
                i++;
            }
        }

        if (res.empty()) {
            res.insert(res.end(), '/');
        }

        return res;
    }
};

class Solution {
  public:
    string simplifyPath(string path) {
        vector<string> v;
        int i = 0;
        while (i < path.size()) {
            //这里先处理'/'
            while (path[i] == '/' && i < path.size()) ++i;
            if (i == path.size()) break;
            int start = i;
            while (path[i] != '/' && i < path.size()) ++i;
            int end = i - 1;
            string s = path.substr(start, end - start + 1);
            //这里的处理和我的理解不一样
            if (s == "..") {
                if (!v.empty()) v.pop_back();
            } else if (s != ".") {
                v.push_back(s);
            }
        }
        if (v.empty()) return "/";
        string res;
        for (int i = 0; i < v.size(); ++i) {
            res += '/' + v[i];
        }
        return res;
    }
};

