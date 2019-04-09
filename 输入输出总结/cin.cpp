#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main() {
    string str;
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

