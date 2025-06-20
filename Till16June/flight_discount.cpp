#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define INF 1e18
void dijkstra(vector<vector<pair<int,int>>>&adj, vector<int>&dist, int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    // dist, node
    dist[start] = 0;
    pq.push({0,start});
    while(!pq.empty()){
        auto [d,node] = pq.top();
        pq.pop();
        if(d > dist[node]) continue;
        for(auto &[a,b] : adj[node]){
            if(dist[b] > a + d){
                dist[b] = a + d;
                pq.push({dist[b],b});
            }
        }
    }

}
void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>>adj1(n + 1);
    vector<vector<pair<int,int>>>adj2(n + 1);
    vector<tuple<int, int, int>> edges;
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        adj1[x].push_back({w,y});
        adj2[y].push_back({w,x});
        edges.emplace_back(x,y,w);
    }
    vector<int>dist1(n + 1,INF);
    vector<int>dist2(n + 1,INF);
    dijkstra(adj1,dist1,1);
    dijkstra(adj2,dist2,n);
    int ans = INF;
    for(auto [a,b,c] : edges){
        ans = min(ans, dist1[a] + c/2 + dist2[b]);
    }
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