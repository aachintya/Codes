#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Sample problem: Find sum of array
    int sum = 0;
    for(int x : arr) {
        sum += x;
    }
    
    cout << "Sum of array: " << sum << endl;
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