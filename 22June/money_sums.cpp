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
    int sum = accumulate(a.begin(), a.end(), 0LL);
    vector<int>dp(sum + 1, false);
    dp[0] = true;
    for(auto coin : a){
        for(int i = sum; i >= coin; i--){
            if(dp[i - coin]){
                dp[i] = true;
            }
        }
    }
     vector<int> result;
    for (int i = 1; i <= sum; ++i) {
        if (dp[i]) {
            result.push_back(i);
        }
    }

    cout << result.size() << "\n";
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << "\n";
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