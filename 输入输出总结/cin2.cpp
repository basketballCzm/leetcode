#include <bits/stdc++.h>
using namespace std;
int main(){
    double n, m;
    // 循环输入n和m的值
    while(cin >> n >> m){
        double sum = 0;
        double tmp = n;
        for(int i = 0; i < m; i++){
            sum += tmp;
            tmp = sqrt(tmp);
        }
        cout << sum << endl;
    }
    return 0;
}