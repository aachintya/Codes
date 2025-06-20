#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = 1;
    map<int,int>mp;
    int j = 0;
    for(int i = 0; i < n; i++){
        j = max(mp[a[i]], j);
        ans = max(ans, i - j + 1);
        mp[a[i]] = i + 1;
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}