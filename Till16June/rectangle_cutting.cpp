#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int a,b;
    cin >> a >> b;
    vector<vector<int>>dp(a + 1, vector<int>(b + 1, 1e9));
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if(i == j){
                dp[i][j] = 0;
            }
            for(int k = 1; k < i; k++){
                dp[i][j] = min(dp[i][j], 1 + dp[i - k][j] + dp[k][j]);
            }
            for(int k = 1; k < j; k++){
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - k] + dp[i][k]);
            }
        }
    }
    cout << dp[a][b] << " ";
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