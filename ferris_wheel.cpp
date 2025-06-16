#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n,k;
    cin >> n >> k;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int i = 0, j = n - 1;
    int ans = 0;
    sort(a.begin(),a.end());
    while(i < j){
        if(a[i] + a[j] <= k){
            ans++;
            i++;
            j--;
        }else if(a[i] + a[j] > k){
            ans++;
            j--;
        }
    }
    if(i == j) ans++;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
