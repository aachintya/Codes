#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    map<char,int>mp;
    for(int i = 0; i < n; i++){
        mp[s[i]]++;
    }
    int odd = 0;
    string ans(n, '#');
    char ch;
    int pos = 0;
    for(auto [x,y] : mp){
        if(y % 2 == 1){
            odd++;
            ch = x;
        }
        for(int j = 0; j < y/2; j++){
            ans[pos] = x;
            ans[n - pos - 1] = x;
            pos++;
        }
    }
    if(n % 2 != 0){
        if(odd == 1){
            ans[n/2] = ch;
            cout << ans << endl;
        }else{
            cout << "NO SOLUTION\n";
        }
    }else{
        if(odd == 0){
            cout << ans << endl;
        }else{
            cout << "NO SOLUTION\n";
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