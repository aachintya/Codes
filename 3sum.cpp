#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(),a.end());
    int flag = 1;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            int l = j + 1;
            int r = n - 1;
            while(l < r){
                int sum = a[i].first + a[j].first + a[l].first + a[r].first;
                if(sum == k){
                    cout << a[i].second + 1 << " " << a[j].second + 1 << " " << a[l].second + 1 << " " << a[r].second + 1 << endl;
                    flag = 0;
                    break;
                }else if(sum < k){
                    l++;
                }else if(sum > k){
                    r--;
                }
            }
            if(flag == 0) break;
        }
        if(flag == 0) break;
    }
    if(flag){
        cout << "IMPOSSIBLE\n";
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
