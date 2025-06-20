#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>>multiples(n + 1);
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j += i){
            multiples[i].push_back(j);
        }
    }
    vector<vector<int>>dp(n + 1, vector<int>(k + 1,-1));
    auto dfs = [&](auto && dfs, int i, int rem){
        if(rem == 0){
            return 1;
        }
        if(dp[i][rem] != -1){
            return dp[i][rem];
        }
        int res = 0;
        for(auto j : multiples[i]){
            res = (res + dfs(dfs, j, rem - 1)) % mod;

        }
        return res % mod;
    };
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum = (sum + dfs(dfs, i, k - 1)) % mod; 
    }
    cout << sum << endl;
}