#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>a(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        vector<vector<int>>adj(n + 1);
        for(int i = 1; i < n; i++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>dp1(n + 1,0);
        vector<int>dp2(n + 1,0);
        function<void(int,int)>dfs = [&](int u, int p){
            if(p == 0){
                dp1[u] = a[u];
                dp2[u] = -a[u];
            }else{
                dp1[u] = a[u] + max(0LL, dp2[p]);
                dp2[u] =  -a[u] + max(0LL, dp1[p]);
            }
            for(auto v : adj[u]){
                if(v != p){
                    dfs(v,u);
                }
            }
        };
        dfs(1,0);
        for(int i = 1; i <= n; i++){
            cout << dp1[i] << " ";
        }
        cout << endl;
    }

}