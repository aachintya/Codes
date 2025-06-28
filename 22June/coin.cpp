#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int a,b;
    cin >> a >> b;
    int x = 2 * b - a;
    int y = 2 * a - b;
    if(x >= 0 && y >= 0 && x % 3== 0 && y %3 ==0 ){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}