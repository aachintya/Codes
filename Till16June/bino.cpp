#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int mod = 1e9 + 7;
#define MAX 1000005
vector<int>fact(MAX);
vector<int>inv_fact(MAX);
int binpow(int a, int b){
    int res = 1;
    while(b > 0){
        if(b & 1){
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
void precompute(){
    fact[0] = 1;
    fact[1] = 1;
    for(int i = 2; i < MAX; i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }
    inv_fact[MAX - 1] = binpow(fact[MAX - 1], mod - 2);
    for(int i = MAX - 2; i >= 0; i--){
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
    }
}
int nCr(int n, int r){
    if(r > n) return 0;
    return fact[n] * inv_fact[n - r] % mod * inv_fact[r] % mod;
}
void solve() {
    int n, r;
    cin >> n >> r;
    cout << nCr(n,r) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    precompute();
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}