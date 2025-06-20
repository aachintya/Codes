#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define INF 1e18
void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>>adj(n + 1);
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
    }
    // pq - {dist,node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    vector<int>dist(n + 1, INF);
    dist[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        auto [d, node] = pq.top();
        pq.pop();
        if(dist[node] < d) continue;
        for(auto &[x,y] : adj[node]){
            if(dist[x] > y + d){
                dist[x] = y + d;
                pq.push({dist[x], x});
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INF) cout << "INF";
        else cout << dist[i] << " ";
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