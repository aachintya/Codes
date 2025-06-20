#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector<vector<int>>adj(n + 1);
    for(int i = 1; i < n; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int ans = 0;
    vector<int>subtreeSize(n + 1);
    auto dfs = [&](auto &&dfs,int u, int p, int depth) ->void {
        ans += depth;
        subtreeSize[u] = 1;  
        for(auto v : adj[u]){
            if(v == p) continue;
            dfs(dfs, v, u, depth + 1);
            subtreeSize[u] += subtreeSize[v];
        }
    };
    dfs(dfs, 1, 0, 0);
    vector<int>dp(n + 1,0);
    dp[1] = ans;
    auto dfs2 = [&](auto && dfs2, int u, int p) -> void{
        for(auto v : adj[u]){
            if(v == p) continue;
            dp[v] = dp[u] + n - 2 * subtreeSize[v];
            dfs2(dfs2,v,u);
        }
    };
    dfs2(dfs2,1,0);
    for(int i = 1; i <= n; i++){
        cout << dp[i] << " ";
    }
    cout << endl;
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