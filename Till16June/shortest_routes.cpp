#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define INF 1e9
void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>>adj(n + 1);
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    
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