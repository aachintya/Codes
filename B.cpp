#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    int n;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        int cnt1 = count(s.begin(),s.end(),'1');
        int cnt0 = n - cnt1;
        int hi = cnt0/2 + cnt1/2;
        int lo = abs(cnt1 - cnt0)/2;
        if(k >= lo && k <= hi && (k - lo) % 2 == 0){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}