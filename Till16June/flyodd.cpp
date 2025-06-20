#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define INF 1e18
void solve() {
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<int>>dist(n + 1, vector<int>(n + 1,INF));
    for(int i = 1; i <= n; i++){
        dist[i][i] = 0;
    }
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dist[i][k] < INF && dist[k][j] < INF){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    while(q--){
        int x,y;
        cin >> x >> y;
        cout << ((dist[x][y] == INF) ? -1 : dist[x][y]) << endl;
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