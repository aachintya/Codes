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
    int mx = *max_element(a.begin(),a.end());
    vector<int>freq(mx + 1,0);
    for(int i = 0; i < n; i++){
        freq[a[i]]++;
    }
    int count = 0;
    int flag = 1;
    for(int i = mx; i >= 0 && flag == 1; i--){
        count = 0;
        for(int j = i; j <= mx; j += i){
            count += freq[j];
            if(count >= 2){
                flag = 0;
                cout << i << endl;
                break;
            }
        }
    }
    if(flag){
        cout << 1 << endl;
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