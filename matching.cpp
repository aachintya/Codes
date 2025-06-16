#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&adj, int child, int parent, vector<vector<int>>&dp){
    for(auto neighbour : adj[child]){
        if(neighbour == parent) continue;
        dfs(adj, neighbour, child, dp);
        dp[child][0] += max(dp[neighbour][1], dp[neighbour][0]);
    }
    for(auto neighbour : adj[child]){
        if(neighbour == parent) continue;
        int cand = 1 + dp[neighbour][0] + (dp[child][0] - max(dp[neighbour][0], dp[neighbour][1]));
        dp[child][1] = max(dp[child][1], cand);
    }
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>>adj(n + 1);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>>dp(n + 1, vector<int>(2,0));
    dfs(adj,1,0,dp);
    cout << max(dp[1][0], dp[1][1]) << endl;
}