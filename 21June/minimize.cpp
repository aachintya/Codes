#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<int>a(n);
    vector<int>b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    vector<int>diff;
    for(int i = 0; i < n; i++){
        diff.push_back(abs(a[i] - b[i]));
    }
    int k = k1 + k2;
    for(int i = 1; i <= k; i++){
        sort(diff.rbegin(), diff.rend());
        diff[0]--;
        diff[0] = abs(diff[0]);
    }
    int ans = 0;
    for(int i = 0; i < diff.size(); i++){
        ans += diff[i] * diff[i];
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}