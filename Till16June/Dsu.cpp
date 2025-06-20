#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
class DSU{
    private:
        vector<int>parents;
        vector<int>sz;
        int components;
        int maxSize;
    public:
        DSU(int n){
            parents.resize(n + 1);
            sz.resize(n + 1,1);
            for(int i = 1; i <= n; i++){
                parents[i] = i;
            }
            components = n;
            maxSize = 1;
        }
        int find(int x){
            return (parents[x] == x) ? x : parents[x] = find(parents[x]);
        }
        bool unite(int a, int b){
            int x_root = find(a);
            int y_root = find(b);
            if(x_root == y_root){
                return false;
            }
            if(sz[x_root] < sz[y_root]){
                swap(x_root, y_root);
            }
            sz[x_root] += sz[y_root];
            parents[y_root] = x_root;
            components--;
            maxSize = max(maxSize, sz[x_root]);
            return true;
        }
        bool connected(int x, int y){
            return (find(x) == find(y));
        }
        int size(int x){
            return sz[find(x)];
        }
        int getComponents() {
            return components;
        }

        int getMaxSize() {
            return maxSize;
        }

};
void solve() {
    int n,m;
    cin >> n >> m;
    DSU dsu(n);
    while(m--){
        int x, y;
        cin >> x >> y;
        dsu.unite(x, y);
        cout << dsu.getComponents() << " " << dsu.getMaxSize() << endl;
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