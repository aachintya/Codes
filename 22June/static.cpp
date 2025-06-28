#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
class FenwickTree{
    private:
        vector<int>bit;
        int n;
    public:
        FenwickTree(int n){
            bit.resize(n + 1,0LL);
            this->n = n;
        }
        void update(int i, int delta){
            while(i <= n){
                bit[i] += delta;
                i += (i & -i);
            }
        }
        int query(int i){
            int sum = 0;
            while(i > 0){
                sum += bit[i];
                i -= (i & -i);
            }
            return sum;
        }
        int query(int l, int r){
            return query(r) - query(l - 1);
        }
};
void solve() {
    int n,q;
    cin >> n >> q;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    FenwickTree fen(n);
    for(int i = 0; i < n; i++){
        fen.update(i + 1, a[i]);
    }

    while(q--){
        int x,y;
        cin >> x >> y;
        cout << fen.query(x,y) << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}