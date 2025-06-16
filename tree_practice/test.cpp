#include<bits/stdc++.h>
using namespace std;
int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>>adj(n);
        for(int i = 0; i < n - 1; i++){
            int x;
            cin >> x;
            x--;
            adj[x].push_back(i + 1);
        }
        int flag = 1;
        for(int i = 0; i < n; i++){
            if(adj[i].size() > 0){
                int count = 0;
                for(auto child : adj[i]){
                    if(adj[child].size() == 0){
                        count++;
                    }
                }
                if(count < 3){
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 1){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}