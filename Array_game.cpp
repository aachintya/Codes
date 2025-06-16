#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        if(k >= 3){
            cout << 0 << endl;
            continue;
        }
        sort(a.begin(),a.end());
        int mx = a[0];
        for(int i = 0; i < n - 1; i++){
            mx = min(mx, a[i + 1] - a[i]);
        }
        if (k == 1) {
            cout << mx << endl;
            continue;
        }
        if(k == 2){
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    int v = a[j] - a[i];
                    int lb = lower_bound(a.begin(),a.end(),v) - a.begin();
                    if(lb < n){
                        mx = min(mx, abs(a[lb] - v));
                    }
                    if(lb - 1 >= 0){
                        mx = min(mx, v - a[lb - 1]);   
                    }
                }
            }
        }
        cout << mx << endl;
    }
    return 0;
}