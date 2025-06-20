#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    int op = 0;
    
    if (x <= y) {
        if (k >= a) {
            int ops = (k - a) / x;
            op += ops;
            k -= ops * x;
        }
        if (k >= b) {
            int ops = (k - b) / y;
            op += ops;
            k -= ops * y;
        }
    } else {
        if (k >= b) {
            int ops = (k - b) / y;
            op += ops;
            k -= ops * y;
        }
        if (k >= a) {
            int ops = (k - a) / x;
            op += ops;
            k -= ops * x;
        }
    }
    cout << op << endl;
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