#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAXB = 60;

void solve() {
    int n;
    cin >> n;
    cout << 2 * n - 1 << endl;
    cout << 1 << " " << 1 << " " << n  << endl;
    for (int i = 2; i <= n; i++) {
        cout << i << " " << 1 << " " << i - 1<< endl;
        cout << i << " " << i << " " << n << endl;
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
