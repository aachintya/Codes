#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define MAX 2e6 + 5;
vector<int>sum;
int check(int n){
    int x = sqrt(1 + 8 * n);
    if(x * x == 1 + 8 * n){
        if((-1 + x) % 2 == 0){
            return true;
        }else{
            return false;
        }
    }
    return false;
}
void solve() {
    // 44 
    // 1e6 precomputed
    // O(n * t)
    // k * (k + 1)/2 = x
    // k = (- 1 + sqrt(1 + 8x))/2;
    // O(logn * t)
    // O(sqrt(n) * t)
    // 1 3 6 10 15 21 28 36
    int n;
    cin >> n;
    if(check(n)){
        cout << 1 << endl;
    }else{
        int lo = 0;
        int hi = sum.size() - 1;
        int flag = 1;
        while(lo <= hi){
            int s = sum[lo] + sum[hi];
            if(s < n){
                lo++;
            }else if(s > n){
                hi--;
            }else{
                flag = 0;
                break;
            }
        }
        if(flag == 0){
            cout << 2 << endl;
        }else{
            cout << 3 << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 1; (i * (i + 1)/2) < 1e12; i++){
        sum.push_back((i * (i + 1))/2);
    }
    // for(int i = 1; i < sum.size(); i++){
    //     cout << sum[i] << " ";
    // }
    cout << endl;
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}