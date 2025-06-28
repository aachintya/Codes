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
    sort(a.begin(),a.end());
    int i = 0;
    int j = n - 1;
    int ans = 0;
    int charge = 0;
    while(i <= j){
        if(i != j){
            if(charge + a[i] < a[j]){
                ans += a[i];
                charge += a[i];
                i++;
            }else{
                ans += a[j] - charge;
                a[i] -= (a[j] - charge);
                j--;
                ans++;
                charge = 0;
                if(!a[i]) i++;
            }
        }else{
            if(a[i] == 1){
                ans++;
            }else{
                a[i] -= charge;
                if(a[i]==1){
                        ans+=2;
                    }else{
                        ans+=(a[i]+1)/2+1;
                    }
            }
            break;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}