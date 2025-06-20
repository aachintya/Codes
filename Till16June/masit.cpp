#include<bits/stdc++.h>
using namespace std;
#define rep(i,k,n)     for(ll i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define debarr(arr) for(ll xxx = 0; xxx < arr.size(); xxx++) cout <<  arr[xxx] << ' '; cout<< endl;
#define deb(x)         cout << #x << "=" << x << endl
#define deb2(z, x, y)  cout << #z ": (" << x << ", " << y << ")\n";
#define ll    long long
#define pb    push_back
#define mp    make_pair
#define F    first
#define S    second
#define all(x)        x.begin(), x.end()
#define clr(x)        memset(x, 0, sizeof(x))
#define sz(x) (int) (x).size()
#define sortall(x)    sort(all(x))
#define tr(it, a)    for(auto it = a.begin(); it != a.end(); it++)
#define PI    3.1415926535897932384626
typedef pair<int, int>    pii;
typedef pair<ll, ll>    pl;
typedef vector<int>        vi;
typedef vector<ll>        vl;
typedef vector<pii>        vpii;
typedef vector<pl>        vpl;
typedef vector<vi>        vvi;
typedef vector<vl>        vvl;

const int mod = 1000000007;
const int N = 1e6 + 7, M = N;
//=======================

vvi adj1,adj2;
vi vis;
void solve() {
    int n;
    cin >> n;
    vi d1(n),d2(n);

    adj1.clear(),adj1.resize(n);
    adj2.clear(),adj2.resize(n);
    int C;
    for(int x = 0; x < n - 1; ++x){ 
        int u,v;
        cin >> u >> v;
        --u,--v;
        adj1[u].pb(v);
        adj1[v].pb(u);
    }
    for(int x = 0; x < n - 1; ++x){ 
        int u,v;
        cin >> u >> v;
        --u,--v;
        adj2[u].pb(v);
        adj2[v].pb(u);
    }
    int max_depth = -1;
    int furthest;
    auto dfs = [&](auto &&dfs, vvi adj, int u, int p, int d) -> void {
        if(d > max_depth) {
            max_depth = d;  
            furthest = u;
        }
        for(auto v : adj[u]) {
            if(v == p) continue;
            dfs(dfs, adj, v, u, d + 1);
        }
    };
    
    dfs(dfs, adj1, 0, -1, 0);
    int e1 = furthest;
    max_depth = -1;  
    dfs(dfs, adj1, e1, -1, 0);
    int e2 = furthest;
    
    vector<int> dist1(n, 0);  
    vector<int> dist2(n, 0); 
    vector<int> dist3(n, 0);  
    vector<int> dist4(n, 0);
    auto dfs2 = [&](auto &&dfs2, vvi adj, int u, int p, int di, vector<int>& dist) -> void {  
        dist[u] = di;
        for(auto v : adj[u]) {
            if(v == p) continue;
            dfs2(dfs2, adj, v, u, di + 1, dist);
        }
    };
    
    dfs2(dfs2, adj1, e1, -1, 0, dist1);
    dfs2(dfs2, adj1, e2, -1, 0, dist2);
    max_depth = -1;

    dfs(dfs, adj2, 0, -1, 0);
    int e3 = furthest;
    max_depth = -1;  
    dfs(dfs, adj2, e3, -1, 0);
    int e4 = furthest;
    dfs2(dfs2, adj2, e3, -1, 0, dist3);
    dfs2(dfs2, adj2, e4, -1, 0, dist4);
    
    for(int i = 0; i < n; i++) {  
        d1[i] = max(dist1[i], dist2[i]);
    }
    for(int i = 0; i < n; i++) {  
        d2[i] = max(dist3[i], dist4[i]);
    }


    sortall(d2);
    vi suf(n);
    suf[n - 1] = d2[n - 1];
    ll ans = 0;
    for(int x = n - 2; x >= 0; --x){ 
        suf[x] += suf[x + 1];
    }
    debarr(d1);
    debarr(d2);
    for(int x = 0; x < n; ++x){ 
        // z = d[i] + 1 + d[j] >= C + 1 => d[j] >= C - d[i];
        auto itr = lower_bound(all(d2),C - d1[x]);
        if(itr == d2.end()){
            ans += n*C;
        }
        else{ 
            int inx = itr - d2.begin(); // a1 a2 a3 a4
            ans += inx*C;
            ans += suf[inx] + (n - inx)*(d1[x] + 1);
        }
    }
    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
