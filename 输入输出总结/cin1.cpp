#include <bits/stdc++.h>
using namespace std;
// 输入二维数组
int main(){
    int row = 0, col = 0;
    cin >> row >> col;
    vector<vector<int>> v(row, vector<int>(col, 0));
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> v[i][j];
        }
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << v[i][j];
        }
    }
    
}