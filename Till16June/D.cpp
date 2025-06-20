#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector<int>a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    vector<int>op1, op2, op3;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            if(a[j] >= a[j + 1]){
                op1.push_back(j);
                swap(a[j], a[j + 1]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            if(b[j] >= b[j + 1]){
                op2.push_back(j);
                swap(b[j], b[j + 1]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i] >= b[i]){
            op3.push_back(i);
            swap(a[i],b[i]);
        }
    }
    cout << op1.size() + op2.size() + op3.size() << endl;

    for(int i = 0; i < op1.size(); i++){
        cout << 1 << " " << op1[i] + 1 << endl;
    }
    for(int i = 0; i < op2.size(); i++){
        cout << 2 << " " << op2[i] + 1<< endl;
    }
    for(int i = 0; i < op3.size(); i++){
        cout << 3 << " " << op3[i] + 1<< endl;
    }
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