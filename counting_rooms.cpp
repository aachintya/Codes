#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>>adj(n + 1);
    for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>sub(n + 1, 0);
    vector<int>dp(n + 1,0);
    
    function<int(int,int,int)> dfs = [&](int node, int parent, int depth) -> int {
        sub[node] = 1;
        dp[1] += depth;
        for(auto i : adj[node]){
            if(i != parent){
                dfs(i, node, depth + 1);
                sub[node] += sub[i];
            }
        }
        return sub[node];
    };
    
    function<void(int,int)> reroot = [&](int node, int parent) -> void {
        for(auto i : adj[node]){
            if(i != parent){
                dp[i] = dp[node] + n - 2 * sub[i];
                reroot(i, node);
            }
        }
    };
    
    dfs(1, 0, 0);
    reroot(1, 0);
    for(int i = 1; i <= n; i++){
        cout << dp[i] << " ";
    }
    cout << endl;
}