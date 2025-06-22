#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    string s;
    cin >> s;
    cout << s.length() << endl;
    map<char, int> freq;
    // 1 2 3 5
    // 1 2 3 3
    // a - 6
    // b - 1
    // 1 6
    // <= 2
    for (char c : s) {
        freq[c]++;
    }
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