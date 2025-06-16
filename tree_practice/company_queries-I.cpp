#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        dp.resize(n, vector<int>(16,-1));
        for(int i = 0; i < n; i++){
            dp[i][0] = parent[i];
        }
        for(int j = 1; j < 16; j++){
            for(int i = 0; i < n; i++){
                if(dp[i][j - 1] != -1){
                    dp[i][j] = dp[dp[i][j - 1]][j - 1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {

        for(int i = 0; i < 30; i++){
            if((1 << i) & k){
                if(node != -1){
                    node = dp[node][i];
                }
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

int main() {
    /*
    Input:
    5 3
    1 1 2 3
    4 1
    4 2
    4 3
    
    Output:
    3
    2
    1
    */
    
    int n, q;
    cin >> n >> q;
    
    vector<int> parent(n+1);
    parent[1] = -1; 
    
    for (int i = 2; i <= n; i++) {
        cin >> parent[i];
    }
    
    TreeAncestor tree(n+1, parent);
    
    for (int i = 0; i < q; i++) {
        int node, k;
        cin >> node >> k;
        cout << tree.getKthAncestor(node, k) << endl;
    }
    
    return 0;
}