#include <bits/stdc++.h>
using namespace std;
void dfs(int curr , vector<vector<int>>&adj, vector<int>&level, int parent){
    if(parent == -1){
        level[curr] = 0;
    }else{
        level[curr] = level[parent] + 1;
    }
    for(int neighbour : adj[curr]){
        if(neighbour != parent){
            dfs(neighbour, adj, level, curr);
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    vector<vector<int>>adj(n);
    for(int i = 0; i < n; i++){
        int x,y;
        x = a[i].first;
        y = a[i].second;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int>level(n,-1);
    dfs(0, adj, level, -1);
}