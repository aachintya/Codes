#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) q.push(i);
    }
    vector<int> topo;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        topo.push_back(x);
        for (auto u : adj[x]) {
            indegree[u]--;
            if (indegree[u] == 0) q.push(u);
        }
    }
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    const int mod = 1e9 + 7;
    for (auto u : topo) {
        for (auto v : adj[u]) {
            dp[v] = (dp[u] + dp[v]) % mod;
        }
    }
    cout << dp[n] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}