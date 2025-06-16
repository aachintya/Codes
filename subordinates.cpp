#include <bits/stdc++.h>
using namespace std;
int dfs(int curr, int parent, vector<vector<int>>&adj, vector<int>&ans){
    for(int &child:adj[curr]){
        if(child==parent) continue;
        dfs(child,curr,adj,ans);
        ans[curr]+=(1 + ans[child]);
    }
    ans[curr]++;
    return ans[curr];
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>>adj(n+1);
    for(int i=2;i<=n;i++){
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    vector<int>ans(n+1);
    dfs(1,-1,adj,ans);
    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    return 0;
}