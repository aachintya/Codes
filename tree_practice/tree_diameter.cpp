#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= n; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }    
    int farthest = -1;
    int max_depth = -1;
    auto dfs = [&](auto &&dfs, int u, int p ,int depth) -> void {
        if(depth > max_depth){
            max_depth = depth;
            farthest = u;
        } 
        for(auto v : adj[u]){
            if(v == p) continue;
            dfs(dfs,v,u, depth + 1);
        }
    };
    dfs(dfs,1,0,0);
    max_depth = -1;
    dfs(dfs,farthest,0,0);
    cout << max_depth << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
