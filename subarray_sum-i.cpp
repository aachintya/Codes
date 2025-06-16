#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    int x, a, b, c;
    cin >> x >> a >> b >> c;
    
    vector<int> arr(n + 1);
    arr[1] = x;
    for(int i = 2; i <= n; i++){
        arr[i] = (a * arr[i - 1] + b) % c;
    }
    
    vector<int> bitCount(32, 0);
    vector<int> temp;
    temp.reserve(n - k + 1); // Pre-allocate space
    
    // Process first window
    for(int i = 1; i <= k; i++){
        for(int p = 0; p < 32; p++){
            if((1LL << p) & arr[i]){
                bitCount[p]++;
            }
        }
    }
    
    int orResult = 0;
    for(int p = 0; p < 32; p++){
        if(bitCount[p] > 0){
            orResult |= (1LL << p);
        }
    }
    temp.push_back(orResult);
    
    // Process remaining windows
    for(int i = k + 1; i <= n; i++){
        // Remove contribution of element leaving window
        for(int p = 0; p < 32; p++){
            if((1LL << p) & arr[i - k]){
                bitCount[p]--;
            }
        }
        
        // Add contribution of new element
        for(int p = 0; p < 32; p++){
            if((1LL << p) & arr[i]){
                bitCount[p]++;
            }
        }
        
        // Calculate OR result
        orResult = 0;
        for(int p = 0; p < 32; p++){
            if(bitCount[p] > 0){
                orResult |= (1LL << p);
            }
        }
        temp.push_back(orResult);
    }
    
    // Calculate final XOR
    int final = 0;
    for(int val : temp){
        final ^= val;
    }
    
    cout << final << endl;
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