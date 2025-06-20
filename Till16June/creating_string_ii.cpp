#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define MAX 2000005
const int mod = 1e9 + 7;
vector<int>fact(MAX);
vector<int>inv_fact(MAX);

int bin_pow(int a, int b, int MOD){
    int res = 1;
    a %= MOD;
    while(b > 0){
        if(b & 1){
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;  
    }
    return res;
}

void precompute(){
    fact[0] = 1;
    fact[1] = 1;
    for(int i = 1; i < MAX; i++){
        fact[i] = (fact[i - 1] * i) % mod;  
    }
    inv_fact[MAX - 1] = bin_pow(fact[MAX - 1], mod - 2, mod);
    for(int i = MAX - 2; i >= 0; i--){
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;  
    }
}

int nCr(int n, int r){
    if(r > n) return 0;
    return fact[n] * inv_fact[n - r] % mod * inv_fact[r] % mod;
}

// 

void solve() {
    int n, m;
    cin >> n >> m;
    cout << nCr(n + m - 1, n - 1) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}