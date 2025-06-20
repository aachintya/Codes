#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> pref(n + 1, 0);
    for(int i = 1; i <= n; i++){
        pref[i] = arr[i - 1] + pref[i - 1];
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    int i = a;
    int ans = -4e18;
    while(i <= n){
        pq.push({pref[i - a], i - a});
        while(!pq.empty() && pq.top().second < i - b){
            pq.pop();
        }
        ans = max(ans,pref[i] - pq.top().first);
        i++;
    }
    cout << ans << endl;
}