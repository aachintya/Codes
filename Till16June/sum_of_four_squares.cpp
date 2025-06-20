#include <bits/stdc++.h>
using namespace std;
#define endl "\n"


string l, r;
int n;
int dp[11][2][2];

int dfs(int pos, int tl, int tr) {
    if (pos == n) {
        return 0;
    }
    if (dp[pos][tl][tr] != -1) {
        return dp[pos][tl][tr];
    }
    dp[pos][tl][tr] = 1e9;
    int lo = tl ? (l[pos] - '0') : 0;
    int hi = tr ? (r[pos] - '0') : 9;

    for (int d = lo; d <= hi; d++) {
        int cost = 0;
        if (d == l[pos] - '0') {
            cost++;
        }
        if (d == r[pos] - '0') {
            cost++;
        }
        int ntl = tl && (d == lo);
        int ntr = tr && (d == hi);
        dp[pos][tl][tr] = min(dp[pos][tl][tr], cost + dfs(pos + 1, ntl, ntr));
    }

    return dp[pos][tl][tr];
}

void solve() {
    cin >> l >> r;
    n = l.size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 2; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    int ans = dfs(0, 1, 1);
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
