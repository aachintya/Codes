#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] % 10 == 1) {
            a[i] += 1;
        }
        else if(a[i] % 10 == 3){
            a[i] += 3;
        }
        else if(a[i] % 10 == 5){
            a[i] += 5;
        }
        else if(a[i] % 10 == 7){
            a[i] += 7;
        }
        else if(a[i] % 10 == 9){
            a[i] += 9;
        }
    }
    if(*max_element(a.begin(), a.end()) == *min_element(a.begin(), a.end())) {
        cout << "Yes" << endl;
    }else{
        // 2 ,4, 6, 8
        int mx = *max_element(a.begin(), a.end());
        if(mx % 10 == 0){
            cout << "No" << endl;
        }else{
            int flag = 0;
            for(int i = 0; i < n; i++){
                while (a[i] % 10 != 2 && a[i] % 10 != 0) {
                    a[i] += a[i] % 10;
                }
            }
            sort(a.begin(),a.end());
            for(int i = 1; i < n; i++){
                if((a[i] - a[i-1]) % 20 != 0){
                    flag = 1;
                    break;
                }
            }
            if(flag){
                cout << "No" << endl;
            }else{
                cout << "Yes" << endl;
            }
        }
    }
    }
    return 0;
}