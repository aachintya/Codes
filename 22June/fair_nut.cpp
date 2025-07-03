#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    string s;
    cin >> s;
    s += 'b';
    int n = s.length();
    //aaaaaa p times , b /// aaaaaaaaaa k times bbbbb r times ////aaaaaa k times
    //p + (2^p - 1) + k  and so on
    int ans = 0;
    int counta = 0;
    const int mod = 1e9 + 7;
    for(int i = 0; i < n; i++){
        if(s[i] == 'a'){
            counta++;
        }else if(s[i] == 'b'){
            if(counta != 0){
                if(ans == 0){
                    ans = (counta + 1);
                    ans %= mod;
                }else{
                    ans *= (counta + 1);
                    ans %= mod;
                }   
            }
            counta = 0;
        }
    }
    cout << max(ans-1,0LL) << endl;
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