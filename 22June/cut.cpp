#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector<vector<int>>adj(n + 1);
    for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(n & 1){
        cout << -1 << endl;
        return;
    }
    vector<int>dp(n + 1,0);
    int ans = 0;
    function<void(int,int)> dfs = [&](int u, int p){
        dp[u] = 1;
        for(auto v : adj[u]){
            if(v == p) continue;
            dfs(v, u);
            dp[u] += dp[v];
        }
        if(dp[u] != n && dp[u] % 2 == 0){
            ans++;
        }
    };
    dfs(1,-1);
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}