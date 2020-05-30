#include <bits/stdc++.h>
using namespace std;
int n,m,sx,sy,ex,ey;
int vis[1001][1001];
struct node{
    int x;
    int y;
    int cnt;
    int stp;
};

int BFS(vector<string>& v){
    deque<node> q;
    node st;
    st.x = sx;
    st.y = sy;
    st.cnt = 5;
    st.stp = 0;
    q.push_back(st);
    while(!q.empty()){
        node st = q.front();
        q.pop_front();
        
    }
}

int main(){
    cin >> n >> m;
    vector<string> v(n,"");
    for(int i = 0; i < v.size(); i++){
        cin >> v[i];
    }

    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            if('S' == v[i][j]){
                sx = i;
                sy = j;
            }

            if('E' == v[i][j]){
                ex = i;
                ey = j;
            }
        }
    }

    cout << BFS(v) << endl;
    return 0;
}