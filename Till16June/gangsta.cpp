/*
s1s2s3....sn
number of zero = c0
number of ones = c1
max(c0,c1) = (c0 + c1 + |c0 - c1|)/2;
 => length of substring + pref[r] - pref[l - 1] for all pairs 
 length of substring = (1 + 2 + 3.... + n) + (1 + 2 + 3..... + n - 1) + (1 + 2 +3 .........+ n - 2)
 => n(n + 1)/2 + n(n - 1)/2  + (n-2)(n -1)/2 + ...........1
 => sigma 1 to n k(k + 1)/2 
 => (k^2 + k)/2
 => n(n + 1)(2n + 1)/12 + n(n + 1)/2
 => n(n + 1)(n + 2)/6
*/ 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
class FenwickTree{
    private:
        vector<int>bit;
        int n;
    public:
        FenwickTree(int n){
            bit.resize(n + 1,0);
            this->n = n;
        }
    void update(int i, int delta){
        while(i <= n){
            bit[i] += delta;
            i += (i & -i);
        }
    }
    int query(int i){
        int sum = 0;
        while(i > 0){
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }
    int query(int l, int r){
        return query(r) - query(l - 1);
    }

};
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int>pref(n + 1,0);
    for(int i = 0; i < n; i++){
        pref[i + 1] = pref[i] + ((s[i] == '1') ? 1 : -1);
    }
    int ans = n*(n + 1)*(n + 2)/6;
    vector<int> b = pref;
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    int m = b.size();
    auto get = [&](int x){
        return (int)(lower_bound(b.begin(), b.end(), x) - b.begin() + 1);
    };
    FenwickTree cnt(m), summa(m);
    for(int i = 0; i <= n; i++){
        int idx = get(pref[i]);
        int sumL = summa.query(idx - 1);
        int cntL = cnt.query(idx - 1);
        int add1 = pref[i] * cntL - sumL;

        int cntH = cnt.query(idx, m);
        int sumH = summa.query(idx, m);
        int add2 = sumH - cntH * pref[i];
        ans += (add1 + add2);
        cnt.update(idx, 1);
        summa.update(idx, pref[i]); 
    }
    cout << ans/2 << endl;
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