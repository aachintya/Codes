#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
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
            int s = 0;
            while(i > 0){
                s += bit[i];
                i -= (i & -i);
            }
            return s;
        }
};
void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [&](const pair<int,int>&a, const pair<int,int>&b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first < b.first;
    });
    vector<int>curr(n);
    for(int i = 0; i < n; i++){
        curr[i] = a[i].second;
    }
    vector<int>b = curr;
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()), b.end());
    auto get = [&](int x){
        return (int)(lower_bound(b.begin(),b.end(),x) - b.begin() + 1);
    };
    // 100 8 6 9 5 10
    // 0 + 1 + 2 + 1 + 4 + 1 
    int ans = 0;
    int m = b.size();
    FenwickTree fen(m);
    for(int i = 0; i < n; i++){
        int idx = get(curr[i]);
        ans += fen.query(m) - fen.query(idx);
        fen.update(idx, 1);
    }
    cout << ans << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
     cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}