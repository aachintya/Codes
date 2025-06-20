#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    stack<pair<int,int>>st;
    vector<int>ans(n,-1);
    for(int i = 0; i < n; i++){
        while(!st.empty() && st.top().first >= a[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = 0;
        }else{
            auto &[x,y] = st.top();
            ans[i] = y + 1;
        }
        st.push({a[i], i});
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
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
