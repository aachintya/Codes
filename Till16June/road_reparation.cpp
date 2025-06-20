#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
class DSU{
    private:
        vector<int>parents;
        vector<int>sz;
        int components;
    public:
        DSU(int n){
            parents.resize(n + 1);
            sz.resize(n + 1,1);
            components = n;
            for(int i = 1; i <= n; i++){
                parents[i] = i;
            }
        }
        int find(int x){
            if(parents[x] != x){
                parents[x] = find(parents[x]);
            }
            return parents[x];
        }
        bool unite(int a, int b){
            int x_root = find(a);
            int y_root = find(b);
            if(x_root == y_root){
                return false;
            }
            if(sz[x_root] < sz[y_root]){
                swap(x_root,y_root);
            }
            sz[x_root] += sz[y_root];
            parents[y_root] = x_root;
            components--;
            return true;
        }
        int component() const{
            return components;
        }
        int size(int x){
            return sz[find(x)];
        }
};
void solve() {
    int n,m;
    cin >> n >> m;
    vector<tuple<int,int,int>>edges;
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges.emplace_back(w,u,v);
    }
    sort(edges.begin(),edges.end());
    int count = 0;
    int total = 0;
    DSU dsu(n);
    for(auto [c, a, b] : edges){
        if(dsu.unite(a,b)){
            total += c;
            count++;
        }
    }
    if(count == n - 1){
        cout << total << endl;
    }else{
        cout << "IMPOSSIBLE\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}