#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    int max_depth = -1;
    int furthest;
    auto dfs = [&](auto &&dfs, int u, int p, int d) -> void {
        if(d > max_depth) {
            max_depth = d;  
            furthest = u;
        }
        for(auto v : adj[u]) {
            if(v == p) continue;
            dfs(dfs, v, u, d + 1);
        }
    };
    
    dfs(dfs, 1, 0, 0);
    int e1 = furthest;
    max_depth = -1;  
    dfs(dfs, e1, 0, 0);
    int e2 = furthest;
    
    vector<int> dist1(n + 1, 0);  
    vector<int> dist2(n + 1, 0); 
    
    auto dfs2 = [&](auto &&dfs2, int u, int p, int di, vector<int>& dist) -> void {  // Fixed: pass dist by reference
        dist[u] = di;
        for(auto v : adj[u]) {
            if(v == p) continue;
            dfs2(dfs2, v, u, di + 1, dist);
        }
    };
    
    dfs2(dfs2, e1, 0, 0, dist1);
    dfs2(dfs2, e2, 0, 0, dist2);
    
    for(int i = 1; i <= n; i++) {  
        cout << max(dist1[i], dist2[i]) << " ";
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
