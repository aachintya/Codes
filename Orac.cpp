#include <bits/stdc++.h>
using namespace std;
long long calc_gcd(long long a, long long b){
    if(b==0) return a;
    return calc_gcd(b,a%b);
}
long long lcm(long long a, long long b){
    return (a*b)/calc_gcd(a,b);
}
// lcm(a, gcd(b,c)) = gcd(lcm(a,b),c)
int main(){
    int t = 1;
    //cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        vector<int>suffix_gcd(n);
        suffix_gcd[n-1] = a[n-1];
        for(int i=n-2;i>=0;i--){
            suffix_gcd[i] = calc_gcd(suffix_gcd[i+1],a[i]);
        }
        vector<int>arr;
        for(int i = 0; i < n - 1; i++){
            arr.push_back(lcm(a[i],suffix_gcd[i+1]));
        }
        int ans = arr[0];
        for(int i = 0; i < arr.size(); i++){
            ans = calc_gcd(ans,arr[i]);
        }
        cout << ans << endl;
    }
}