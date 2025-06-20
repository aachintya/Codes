#include <bits/stdc++.h>
using namespace std;
int dfs(int curr, int parent, vector<vector<int>>&adj, vector<int>&subtreeSum, vector<int>&ans, vector<int>&road){
    if(road[curr] == 1){
        subtreeSum[curr]++;
    }
    for(auto child : adj[curr]){
        if(child != parent){
            subtreeSum[curr] += dfs(child, curr, adj, subtreeSum, ans, road);
        }
    }
    return subtreeSum[curr];
}
int main(){
    int n;
    cin >> n;
    int count = 0;
    vector<vector<int>>adj(n+1); 
    vector<int>road(n+1,0);
    for(int i = 0; i < n - 1; i++){
        int u,v,w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u+1].push_back(v+1);
        adj[v+1].push_back(u+1);
        if(w == 2){
            road[u+1] = 1;
            road[v+1] = 1;
        }
    }
    vector<int>ans(n+1,0);
    vector<int>subtreeSum(n+1,0);
    dfs(1, 0, adj, subtreeSum, ans, road);
    vector<int>rep;
    for(int i = 1; i <= n; i++){
        if(subtreeSum[i] > 0 && subtreeSum[i] == road[i]){
            rep.push_back(i);
        }
    }
    cout << rep.size() << endl;
    for(int i = 0; i < rep.size(); i++){
        cout << rep[i] << " ";
    }
    cout << endl;
}