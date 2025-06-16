#include <bits/stdc++.h>
using namespace std;
// intime and outtime

vector<int>subtree;
vector<int>in,out;
int timer = 0;
void dfs(int node, int parent, vector<vector<int>>&adj){
    subtree[node] = 1;
    in[node] = timer++;
    for(int child : adj[node]){
        if(child != parent){
            dfs(child, node, adj);
            subtree[node] += subtree[child];
        }
    }
    out[node] = timer++;
}
int main(){
    int n,x,y;
    cin >> n >> x >> y;
    x--;
    y--;
    vector<vector<int>>adj(n);
    for(int i = 0; i < n - 1; i++){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    long long val = n*(n - 1);
    subtree.resize(n, 0);  

    subtree.resize(n, 0);
    in.resize(n, 0);
    out.resize(n, 0);
    timer = 0;

    dfs(y, -1, adj);
    int wow = n;
    for(auto child : adj[y]){
        if(in[child] <= in[x] && out[child] >= out[x]){
            wow -= subtree[child];
            break;
        }
    }
     cout << val - 1LL * subtree[x] * wow << endl; 
}