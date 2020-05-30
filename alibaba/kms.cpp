#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N (1000000000+7)
ll ksm(ll a, ll b){
    ll res = 1, ans = 1;
    while(b){
        if(b&1){
            ans = (ans*res)%N;
        }
        res = (res*res)%N;
        b >> 1;
    }
    return ans%N;
}

int main(){
    ll n;
    cin >> n;
    cout << (n*ksm(2,n-1))%N;
    return 0;
}
