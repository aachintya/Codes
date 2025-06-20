#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<vector<int>>&adj, vector<int>&a, int curr, int& m, int& leaf_count){
    if(curr > m){
        return;
    }
    
    if(a[node] == 1){
        curr++;
    }else{
        curr = 0;
    }
    bool is_leaf = true;
    for(auto neighbor : adj[node]){
        if(neighbor != parent){
            is_leaf = false;
            dfs(neighbor, node, adj, a, curr, m, leaf_count);
        }
    } 
    if(is_leaf && curr <= m){
        leaf_count++;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    vector<vector<int>>adj(n);
    for(int i = 0; i < n-1; i++){  
        int u, v;
        cin >> u >> v;
        u--; v--;  
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int leaf_count = 0;
    dfs(0, -1, adj, a, 0, m, leaf_count);  
    cout << leaf_count << endl;
    return 0;
}