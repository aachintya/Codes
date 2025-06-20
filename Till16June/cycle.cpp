#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define INF LLONG_MAX/4
void solve() {
    int n,m;
    cin >> n >> m;
    vector<tuple<int,int,int>> edges;
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        edges.emplace_back(x, y, z);
    }
    vector<int>dist(n + 1,INF);
    vector<int>parent(n + 1, -1);
    dist[1] = 0;
    int x = -1;
    for(int i = 1; i <= n; i++){
        x = -1;
        for(auto [u, v, wt] : edges){
            if(dist[u] + wt < dist[v]){
                dist[v]= dist[u] + wt;
                parent[v] = u;
                x = v;
            }
        }
    }
    if(x == -1){
        cout << "NO\n";
    }else{
        int y = x;
        for(int i = 0; i < n; i++){
            y = parent[y];
        }
        vector<int>cycle;
        for(int curr = y;; curr = parent[curr]){
            cycle.push_back(curr);
            if(curr == y && cycle.size() > 1) break;
        }
        reverse(cycle.begin(),cycle.end());
        cout << "YES\n";
        for(auto i : cycle){
            cout << i << " ";
        }
        cout << endl;
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