#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int diff = LLONG_MAX/4;
    int total = accumulate(a.begin(),a.end(),0LL);
    for(int mask = 0; mask < (1 << n);  mask++){
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(mask & (1LL << i)){
                sum += a[i];
            }
        }
        int other = total - sum;
        diff = min(diff, abs(other - sum));
    }
    cout << diff << endl;
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