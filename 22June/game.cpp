#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;

ll mod_exp(ll a, ll b){
    ll res = 1;
    a %= mod;
    while(b > 0){
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n+1);
    for(int i = 1; i < n; i++){
        int u, v, x;
        cin >> u >> v >> x;
        if(x == 0){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    vector<char> vis(n+1, 0);
    ll bad = 0;
    function<ll(int)> dfs = [&](int u){
        vis[u] = 1;
        ll cnt = 1;
        for(int v : adj[u]){
            if(!vis[v]){
                cnt += dfs(v);
            }
        }
        return cnt;
    };

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            ll sz = dfs(i);
            bad = (bad + mod_exp(sz, k)) % mod;
        }
    }

    ll total = mod_exp(n, k);
    ll good = (total - bad + mod) % mod;
    cout << good << '\n';
    return 0;
}
