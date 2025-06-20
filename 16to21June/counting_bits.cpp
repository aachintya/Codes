#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    map<int,int>mp;
    auto solve =  [&](auto &&solve, int n)->int{
        if(n == 1) return 1;
        if(n == 0) return 0;
        if(mp[n]) return mp[n];
        if(n % 2 != 0){
            return mp[n] = 2 * solve(solve,n/2) + n/2 + 1;
        }else{
            return mp[n] = solve(solve,n/2 - 1) + solve(solve,n/2) + n/2;
        }
    };
    cout << solve(solve,n) << endl;
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