
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int>l(n + 1), r(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> l[i] >> r[i];
    }
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>>dp(n + 1, vector<int>(2,0));
    // max matching when u is matched (1) and not matched (0);
    auto dfs = [&](auto &&dfs, int u, int p) -> void{
        for(auto v : adj[u]){
            if(v == p) continue;
            dfs(dfs, v, u);
            dp[u][0] += max(abs(l[u] - l[v]) + dp[v][0], abs(l[u] - r[v]) + dp[v][1]);
            dp[u][1] += max(abs(r[u] - l[v]) + dp[v][0], abs(r[u] - r[v]) + dp[v][1]);
        }
    };
    dfs(dfs, 1, 0);
    cout << max(dp[1][0], dp[1][1]) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}