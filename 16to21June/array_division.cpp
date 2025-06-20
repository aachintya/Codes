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
    int lo = *min_element(a.begin(),a.end());
    int hi = accumulate(a.begin(),a.end(),0LL);
    int ans = 0;
    auto check = [&](int mid){
        int subarrays = 1; 
        int curr = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(sum + a[i] > mid){
                curr = max(curr, sum);
                subarrays++;
                sum = a[i];
            }else {
                sum += a[i];
            }
        }
                        curr = max(curr, sum);
        return subarrays <= k && curr <= mid; 
    };
    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(check(mid)){
            ans = mid;
            //cout << mid << endl;
            // cout << ans << endl;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    cout << ans << endl;
}