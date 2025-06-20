#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int MAX = 1000000;
vector<int>divisor(MAX + 1, 0);
void solve() {
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        cout << divisor[x] << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 1; i <= MAX; i++){
        for(int j = i; j <= MAX; j+=i){
            divisor[j]++;
        }
    }
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}