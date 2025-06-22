#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}
void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int g = a[0];
    for(int i = 1; i < n; i++){
        g = gcd(g, a[i]);
    }
    if(g != 1){
        cout << -1 << endl;
        return;
    }
    int ans = LLONG_MAX;
    for(int i = 0; i < n; i++){
        int g = 0;
        for(int j = i; j < n; j++){
            g = gcd(g, a[j]);
            if(g == 1){
                ans = min(ans, j - i);
            }
        }
    }
    int c = count(a.begin(),a.end(),1);
    if(c > 0){
        cout << n - c << endl;
    }else{
        cout << n - 1 + ans << endl;
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