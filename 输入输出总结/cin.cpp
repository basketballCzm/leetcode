#include <bits/stdc++.h>
using namespace std;
// 循环输入整数
int main() {
    string str;
    // 多次输入形式重复的数据
    // while(cin >> k)
    while (getline(cin, str)) {
        vector<int> num;
        int temp;
        istringstream iss(str);
        while (iss >> temp) {
            num.push_back(temp);
        }
        // 输出显示
        for (int i = 0; i < num.size(); i++)
            cout << num[i] << " ";
        cout << endl;
    }
}


