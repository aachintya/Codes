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
    int lo = 1;
    int hi = 1e18;
    int ans = 0;
    auto check = [&](int mid){
        int s = 0;
        for(int i = 0; i < n; i++){
            s += mid/a[i];
        }
        return s >= k;
    };
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(check(mid)){
            ans = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    cout << ans << endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}