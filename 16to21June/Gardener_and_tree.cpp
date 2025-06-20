#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> adj(n);
        vector<int> degree(n,0);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i]<=1){
                q.push(i);
            }
        }
        int ans = 0;
        while(!q.empty() && k--){
            int cnt = q.size();
            for(int i=0;i<cnt;i++){
                int leaf = q.front();
                q.pop();
                ans++;
                for(auto it:adj[leaf]){
                    degree[it]--;
                    if(degree[it]==1){
                        q.push(it);
                    }
                }
            }
        }
        cout <<n - ans << endl;

    }
}