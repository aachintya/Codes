#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, int> freq;
    unordered_map<int, set<int>> mp;
    int maxF = 0;
    vector<int> ans;
    
    for(int i = 0; i < k; i++) {
        int x = a[i];
        int f = freq[x]++;
        if(f > 0) {
            mp[f].erase(x);
        }
        mp[f + 1].insert(x);
        maxF = max(f + 1, maxF);
    }
    ans.push_back(*mp[maxF].begin());
    for(int i = k; i < n; i++) {
        int out = a[i - k];
        int fo = freq[out]--;
        mp[fo].erase(out);
        if(mp[fo].empty()) {
            mp.erase(fo);
        }
        if(fo > 1) {
            mp[fo - 1].insert(out);
        }
        if(!mp.count(maxF)) {
            maxF--;
        }
        
        int in = a[i];
        int fi = freq[in]++;
        if(fi > 0) {
            mp[fi].erase(in);
            if(mp[fi].empty()) {
                mp.erase(fi);
            }
        }
        mp[fi + 1].insert(in);
        maxF = max(maxF, fi + 1);
        
        ans.push_back(*mp[maxF].begin());
    }
    
    for(int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}