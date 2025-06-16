#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> parent(n + 1);
    parent[1] = 0;
    for (int i = 2; i <= n; i++) {
        cin >> parent[i];
    }

    int LOG = 0;
    while ((1 << LOG) <= n) {
        LOG++;
    }
    vector<vector<int>> dp(n + 1, vector<int>(LOG, 0));
    for (int i = 1; i <= n; i++) {
        dp[i][0] = parent[i];
    }
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }

    while (q--) {
        int x, k;
        cin >> x >> k;
        for (int j = 0; j < LOG && x; j++) {
            if (k & (1 << j)) {
                x = dp[x][j];
            }
        }
        cout << ((x == 0)? -1 : x) << '\n';
    }

    return 0;
}
