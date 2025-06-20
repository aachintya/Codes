#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>>adj(n + 1);
    for(int i = 0; i < m ; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    vector<int>indegree(n + 1,0);
    for(int i = 1; i <= n; i++){
        for(auto u : adj[i]){
            indegree[u]++;
        }
    }
    queue<int>q;
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for(auto u : adj[x]){
            indegree[u]--;
            if(indegree[u] == 0) q.push(u);
        }
    }
    if(ans.size() == n){
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }else{
        cout << "IMPOSSIBLE\n";
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