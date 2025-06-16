#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        bool sorted = true;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] > a[i]) {
                sorted = false;
                break;
            }
        }
        if (sorted) {
            cout << 0 << "\n";
            continue;
        }

        ll lo = 1, hi = (1LL << 30), ans = hi;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            int b = 63 - __builtin_clzll(mid);
            ll m = (1LL << (b + 1)) - 1;

            ll prev = a[0];
            bool ok = true;
            for (int i = 1; i < n; i++) {
                ll low  = a[i];
                ll high = a[i] | m;
                if (high < prev) {
                    ok = false;
                    break;
                }
                prev = max(prev, low);
            }

            if (ok) {
                ans = mid;
                hi  = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
