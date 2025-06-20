#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>& arr,vector<vector<int>>& dp,int i,int k,int z){
    if(i>=arr.size() || i<0){
        return 0;
    }
    if(k==0){
        return arr[i];
    }
    if(dp[i][z]!=-1){
        return dp[i][z];
    }
    int ans = 0;
    if(i + 1 < arr.size()){
        ans = max(ans,arr[i]+solve(arr,dp,i+1,k-1,z));
    }
    if(i > 0 && z > 0){
        ans = max(ans, arr[i] + solve(arr,dp,i - 1,k - 1,z - 1));
    }
    return dp[i][z]=ans;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,k,z;
        cin>>n>>k>>z;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        // dp[i][j] represents maximum sum we can get till index i with j left moves 
        vector<vector<int>> dp(n,vector<int>(z + 1,-1));
        
        int ans=solve(arr,dp,0,k,z);
        cout<<ans  <<endl;
    }
}