#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void dfs(vector<vector<int>>& adj, vector<int>& vis, int u) {
    vis[u] = 1;
    for(auto v : adj[u]) {
        if(!vis[v]) {
            dfs(adj, vis, v);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> rev_adj(n + 1);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }
    
    vector<int> vis1(n + 1, 0), vis2(n + 1, 0);
    dfs(adj, vis1, 1);
    dfs(rev_adj, vis2, 1);
    
    for(int i = 1; i <= n; i++) {
        if(!vis1[i]) {
            cout << "NO\n";
            cout << 1 << " " << i << endl;
            return;
        }
        if(!vis2[i]){
            cout << "NO\n";
            cout << i << " " << 1 << endl;
            return; 
        }
    }
    cout << "YES\n";
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