#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    string s;
    cin >> s;
    vector<int>pref(n,0);
    pref[0] = a[0];
    for(int i = 1; i < n; i++){
        pref[i] = a[i] ^ pref[i - 1];
    }
    int x = 0, y = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            x = x ^ a[i];
        }else{
            y = y ^ a[i];
        }
    }
    int q;
    cin >> q;
    vector<int>ans;
    while(q--){
        int u;
        cin >> u;
        if(u == 2){
            int v;
            cin >> v;
            if(v == 0){
                ans.push_back(x);
            }else{
                ans.push_back(y);
            }
        }else{
            int v,w;
            cin >> v >> w;
            v--; w--; 
            int xor_range = pref[w] ^ (v > 0 ? pref[v - 1] : 0);
            x = x ^ xor_range;
            y = y ^ xor_range;
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
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