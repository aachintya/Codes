#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>>a(n);
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        a[i] = {x,y};
    }
    sort(a.begin(),a.end(), [&](auto &a, auto &b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second < b.second;
    });
    multiset<int>m;
    for(int i = 0; i < k; i++){
        m.insert(0);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x = a[i].first;
        int y = a[i].second;
        auto it = m.upper_bound(x);
        if(it == m.begin()){
            continue;
        }
        m.erase(--it);
        m.insert(y);
        ans++;
    }
    cout << ans << endl;
}