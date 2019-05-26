#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 2 abc 123456789
//字符串的切分和排序
bool cmp (string a, string b) {
    return a < b;
}

int main() {
    int n = 0;
    cin >> n;
    vector<string> v(n, "");
    vector<string> res;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        string tmp = v[i];
        int size = tmp.size();
        int cnt = size / 8;
        for (int j = 0; j < cnt; j++) {
            string tmp1;
            for (int k = 8 * j; k < 8 * (j + 1); k++) {
                tmp1.insert(tmp1.end(), tmp[k]);
            }
            res.push_back(tmp1);
        }

        if (cnt * 8 < size) {
            string tmp1;
            for (int i = 8 * cnt; i < size; i++) {
                tmp1.insert(tmp1.end(), tmp[i]);
            }

            for (int i = size; i < 8 * (cnt + 1); i++) {
                tmp1.insert(tmp1.end(), '0');
            }
            res.push_back(tmp1);
        }
    }

    sort(res.begin(), res.end(), &cmp);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}