#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    
    vector<vector<int>> dist(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // dist, node
    pq.push({0, 1});
    
    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();
        
        if (dist[node].size() >= k) continue;
        dist[node].push_back(d);
        
        for (auto [a, b] : adj[node]) {
            pq.push({d + b, a});
        }
    }
    
    for (int cost : dist[n]) {
        cout << cost << " ";
    }
    cout << "\n";
    
    return 0;
}