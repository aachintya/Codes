#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    map<int,int>mp;
    set<int>missing;
    for(int i = 0; i <= k; i++){
        missing.insert(i);
    }
    for(int i = 0; i < k; i++){
        if(a[i] <= k){
            mp[a[i]]++;
            if(mp[a[i]] == 1){
                missing.erase(a[i]);
            }
        }
    }
    cout << *missing.begin() << " ";
    for(int i = k; i < n; i++){
        int out = a[i - k];
        if(out <= k){
            mp[out]--;
            if(mp[out] == 0){
                missing.insert(out);
                mp.erase(out);
            }
        }
        int in = a[i];
        if(in <= k){
            mp[in]++;
            if(mp[in] == 1){
                missing.erase(in);
            }
        }
        cout << *missing.begin() << " ";
    }
    cout << endl;

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