#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    vector<tuple<int,int,int>> b(n);

    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        a[i] = {x,y};
        b[i] = {x,y,i};
    }

    sort(b.begin(), b.end(), [&](const tuple<int,int,int>& a, const tuple<int,int,int>& b){
        if(get<0>(a) == get<0>(b)){
            return get<1>(a) > get<1>(b);
        }
        return get<0>(a) < get<0>(b);
    });

    for(int i = 0; i < n; i++){
        auto [x, y, z] = b[i];
        auto it = upper_bound(b.begin(), b.end(), y, [](int val, const tuple<int, int, int>& t) {
            return val < get<1>(t);
        });

        if(it != b.begin()) {
            --it;
            auto [a1, b1, c] = *it;
            if (z != c) {
                cout << c + 1 << " " << z + 1 << endl;
                return;
            }
        }
    }

    cout << -1 << " " << -1 << endl;
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc = 1;
    // cin >> t;
    while (tc--) {
        solve();
    }
    
    return 0;
}