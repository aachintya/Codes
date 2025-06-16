#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int s = 0;
    for(int i = 0; i < n - 1; i++){
        s += a[i];
    }
    if(s <= a[n - 1]){
        cout << 2 * a[n - 1] << endl;
    }else{
        cout << s + a[n - 1] << endl;
    }
}