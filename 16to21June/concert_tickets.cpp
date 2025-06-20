#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n,m;
    cin >> n >> m;
    multiset<int>p;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        p.insert(x);
    }    
    vector<int>ti(m);
    for(int i = 0; i < m; i++){
        cin >> ti[i];
    }
    for(int i = 0; i < m; i++){
        auto it = p.lower_bound(ti[i]);
        if(it != p.begin()){
            --it;
            cout << *it << endl;
            p.erase(it);
        }else{
            cout << -1 << endl;
        }
    }
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
