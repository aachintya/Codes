#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,k;
    cin >> n >> k;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int count = 0;
    int ans = 0;
    map<int,int>mp;
    int i = 0, j = 0;
    while(j < n){
        mp[a[j]]++;
        if(mp[a[j]] == 1){
            count++;
        }
        while(count > k){
            mp[a[i]]--;
            if(mp[a[i]] == 0){
                count--;
            }
            i++;
        }
        ans += j - i + 1;
        j++;
    }
    cout << ans << endl;
}