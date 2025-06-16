#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;  // Added missing input for n
    vector<int>a(n);
    map<int,int>mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(a.begin(),a.end());
    vector<int>pref(n,0);
    pref[0] = a[0];
    for(int i = 1; i < n; i++){
        pref[i] = pref[i - 1] + a[i];
        mp[pref[i]]++;
    }

    int lo = 1;
    int hi = 1e18;
    int ans = hi;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(mp.find(mid) != mp.end()){
            ans = mid;  // Fixed: was using lo instead of mid
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    cout << ans << endl;  // Fixed: was using lo instead of ans
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
