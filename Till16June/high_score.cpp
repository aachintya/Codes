#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define INF LLONG_MAX/4

void dfs(vector<vector<int>>&adj, vector<int>&vis, int u){
    vis[u] = 1;
    for(auto v : adj[u]){
        if(!vis[v]){
            dfs(adj,vis,v);
        }
    }
}

void solve() {
    int n,m;
    cin >> n >> m;
    vector<tuple<int,int,int>> edges;
    vector<vector<int>>adj1(n + 1);
    vector<vector<int>>adj2(n + 1);
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges.emplace_back(u,v,-w);
        adj1[u].push_back(v);
        adj2[v].push_back(u);
    }
    vector<int>dist(n + 1,INF);
    dist[1] = 0;
    for(int i = 0; i < n - 1; i++){
        for(auto [u,v,w] : edges){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }
    int flag = 0;
    vector<int> vis1(n + 1, 0), vis2(n + 1, 0);
    dfs(adj1,vis1,1);
    dfs(adj2,vis2,n);
    for(auto [u,v,w] : edges){
        if(dist[u] + w < dist[v]){
            if(vis1[u] && vis2[v]){
                flag = 1;
                break;
            }
        }
    }
    if(flag){
        cout << -1 << endl;
    }else{
        cout << -dist[n] << endl;
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