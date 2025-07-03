#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    vector<int>freq(1e6 + 1);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        freq[x]++;
    }
    for(int i = 1000000; i > 0; i--){
        int count = 0;
        for(int j = i; j <= 1000000; j += i){
            count += freq[j];
        }
        if(count >= 2){
            cout << i << endl;
            return;
        }
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