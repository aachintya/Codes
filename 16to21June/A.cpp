#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    int n;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int>a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int idx = -1;
        for(int i = 0; i < n; i++){
            if(a[i] == 1){
                idx = i;
                break;
            }
        }
        int wow = idx;
        for(int i = idx + 1; i < n; i++){
            if(a[i] == 1){
                wow = i;
            }
        }
        //cout << idx << " " << wow << endl;
        if(wow - idx + 1 <= k){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}
