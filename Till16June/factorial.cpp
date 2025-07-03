#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> factorials;

int countSetBits(int n) {
    int cnt = 0;
    while(n){
        cnt += (n & 1);
        n >>= 1;
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    int ans = LLONG_MAX;

    int sz = factorials.size();
    for(int mask = 0; mask < (1 << sz); mask++){
        int sum = 0;
        int cnt = 0;
        for(int j = 0; j < sz; j++){
            if(mask & (1 << j)){
                sum += factorials[j];
                cnt++;
            }
        }
        if(sum > n) continue;

        int rem = n - sum;
        cnt += countSetBits(rem);
        ans = min(ans, cnt);
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int prod = 1;
    for(int i = 1; i <= 15; i++){
        prod *= i;
        factorials.push_back(prod);
    }

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
