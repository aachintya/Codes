#include <bits/stdc++.h>
using namespace std;
int maxN = 2e5 + 5;
int mod = 1e9 + 7;
vector<vector<int>>dp(maxN,vector<int>(10,0));
void preprocess(){
    for(int i=0;i<=9;i++){
        dp[0][i] = 1;
    }
    for(int i = 1; i < maxN; i++){
        for(int j = 0; j <= 8; j++){
            if(j < 9){
                dp[i][j] = dp[i - 1][j + 1];
            }
        }
        dp[i][9] = (dp[i - 1][1] % mod + dp[i - 1][0] % mod) % mod;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    preprocess();
    while(t--){
        int n,k;
        cin>>n>>k;
        int num = n;
        int ans = 0;
        while(num != 0){
            int d = num % 10;
            ans = (ans + dp[k][d]) % mod;
            num = num/10;
        }
        cout << ans << endl;
    }
}
