#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector<pair<int,int>> ops;
    for (int i = 1; i <= n; i++) {
        if (a[i] > b[i]) {
            ops.pb({3, i});
            swap(a[i], b[i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        int pos = -1;
        for (int j = i; j <= n; j++){
            if (a[j] == i){ 
                pos = j; 
                break; 
            }
        }
        while (pos > i) {
            ops.pb({1, pos-1});
            swap(a[pos], a[pos-1]);
            pos--;
        }
    }
    for (int j = n; j >= 1; j--) {
        int want = n + j;
        int pos = -1;
        for (int k = 1; k <= j; k++)
            if (b[k] == want) { pos = k; break; }
        while (pos > j) {
            ops.pb({2, pos-1});
            swap(b[pos], b[pos-1]);
            pos--;
        }
        while (pos < j) {
            ops.pb({2, pos});
            swap(b[pos], b[pos+1]);
            pos++;
        }
    }
    cout << ops.size() << endl;
    for (auto &p : ops)
        cout << p.first << " " << p.second << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
