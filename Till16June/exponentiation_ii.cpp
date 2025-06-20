#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int MOD = 1e9 + 7;
int bin_pow(int a, int b, int MOD){
    int res = 1;
    while(b > 0){
        if(b & 1){
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
void solve() {
    // A^k mod M = A^(k mod M-1) mod M
    int a, b, c;
    cin >> a >> b >> c;
    if(a == 0 && b == 0 && c == 0){
        cout << 0 << endl;
        return;
    }
    if(a == 0){
        if(b == 0){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }else if(b == 0){
        if(c == 0){
            cout << a << endl;
        }else{
            cout << 1 << endl;
        }
    }else{
        int wow = bin_pow(b, c, MOD - 1);
        int ans = bin_pow(a, wow, MOD);
        cout << ans << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}