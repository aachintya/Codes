#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<tuple<int,int,int>>a(n);
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        a[i] = {x,y,i};
    }
    sort(a.begin(),a.end());
    set<pair<int,int>>m;
    vector<int>ans(n,0);
    int count = 0;
    for(int i = 0; i < n; i++){
        auto &[x,y,z] = a[i];
        if(1){
           auto it = m.lower_bound({x,0});
           if(it != m.begin()){
            --it;
            int room = it->second;
            m.erase(it); 
            ans[z] = room;
            m.insert({y,room});
           }else{
                ++count;
                ans[z] = count;
                m.insert({y,count});
           }
        }
    }
    cout << *max_element(ans.begin(),ans.end()) << endl;
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
