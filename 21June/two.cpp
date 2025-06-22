#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>>a(n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        a[i] = {x,y};
    }
    sort(a.begin(),a.end(),[&](pair<int,int>&c, pair<int,int>&d){
        if(c.first == d.first){
            return c.second > d.second;
        }
        return c.first < d.first;
    });
    multiset<int>st;
    st.insert(-1);
    st.insert(-1);
    int flag = 1;
    for(int i = 0; i < n; i++){
        auto [x,y] = a[i];
        // x ->start, y->end
        auto it = st.lower_bound(x);
        if(it != st.begin()){
            --it;
            st.erase(it);
            st.insert(y);
        }else{
            flag = 0;
            break;
        }
    }
    if(flag){
        cout << "YES\n";
    }else{
        cout << "NO\n";
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