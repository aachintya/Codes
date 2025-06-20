#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int mod = 1e9 + 7;
int mod_exp(int a, int b){
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
void solve() {
    int a,b;
    cin >> a >> b;
    cout << mod_exp(a,b) << endl;
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