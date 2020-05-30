#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define NUM 1000000007

ll kms(ll a, ll b){
    ll ans = 1;
    ll res = a;
    while(b){
        if(b&1){
            ans = (ans*res)%NUM;
        }
        res = (res*res)%NUM;
        b = b >> 1;
    }
    return ans%NUM;
}

ll gcd(ll a, ll b){
    while(0 != b){
        int t = b;
        b = a%b;
        a = t;
    }
    return a;
}

int main(){
    ll a,b;
    cin >> a >> b;
    cout << kms(a, b) << endl;
    cout << gcd(a,b) << endl;
    return 0;
}