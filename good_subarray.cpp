#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int>arr(n);
        for(int i = 0; i < n; i++){
            arr[i] = s[i] - '0' - 1;
        }
        map<int,int>mp;
        mp[0] = 1;
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            ans += mp[sum];
            mp[sum]++;
        }
        cout << ans << endl;
        
        
    }
}
