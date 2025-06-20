#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

bool dfs(int node, int c, vector<vector<int>>& adj, vector<int>& color) {
    color[node] = c;
    for(auto neigh : adj[node]) {
        if(color[neigh] == 0) {
            if(!dfs(neigh, 3 - c, adj, color)) {
                return false;
            }
        } else if(color[neigh] == color[node]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>>adj(n + 1);
    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int>color(n + 1,0);
   
    int flag = 1;
    for(int i = 1; i <= n; i++){
        if(color[i] != 0) continue;
        if(!dfs(i, 1, adj, color)) {
            flag = 0;
            break;
        }
    }
    if(flag == 0){
        cout << "IMPOSSIBLE\n";
    }else{
        for(int i = 1; i <= n; i++){
            cout << color[i] << " ";
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