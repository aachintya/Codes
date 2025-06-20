#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
        
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> vals(n);
    for(int i = 0; i < n; i++) {
        cin >> vals[i];
    }
    
    vector<int> par(n);
    for(int i = 0; i < n; i++) {
        cin >> par[i];
    }
    
    Solution sol;
    cout << sol.goodSubtreeSum(vals, par) << '\n';
    
    return 0;
}