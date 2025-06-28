#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    // dp[i][0] represents max number of matching without taking ith node
    // dp[i][1] represents max number of matching taking ith node
    int n;
    cin >> n;
    int m = n - 1;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    function<void(int, int)> dfs = [&](int u, int p) {
        for(auto v : adj[u]) {
            if(v == p) continue;
            dfs(v, u);
            dp[u][0] += max(dp[v][0], dp[v][1]);
        }
        for(auto v : adj[u]){
            if(v == p) continue;
            dp[u][1] = max(dp[u][1], 1 + dp[v][0] + (dp[u][0] - max(dp[v][0], dp[v][1])));
        }

    };
    dfs(1, -1);
    cout << max(dp[1][0], dp[1][1]) << endl;
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