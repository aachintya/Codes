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
    vector<vector<int>> adj(n + 1);
    for(int i = 2; i <= n; i++){     
        int u;
        cin >> u;
        adj[u].push_back(i);
    }
    vector<int> subtreeSize(n + 1, 0);
    auto dfs = [&](auto &&dfs, int u, int p) -> void {
        for(auto v : adj[u]){
            if(v != p){
                dfs(dfs, v, u);
                subtreeSize[u] += (1 + subtreeSize[v]);
            }
        }
    };
    dfs(dfs, 1, 0);
    for(int i = 1; i <= n; i++){
        cout << subtreeSize[i] << " ";
    }
    cout << endl;
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
