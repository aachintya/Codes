#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n,k;
    cin >> n >> k;
    string s(k,'1');
    for(int i = 0; i < n - k; i++){
        s.push_back('0');
    }
    cout << s << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
     cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
