#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>>adj(n);
    vector<int>parent(n,-1);
    for(int i = 0; i < n - 1; i++){
        int v;
        cin >> v;
        v--;
        adj[v].push_back(i);
        parent[i] = v;
    }
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(adj[i].size() == 0){
            cout << i << endl;
            int p = parent[i];
            if(adj[p].size() < 3){
                flag = 1;
            }
        }
    }
    if(flag == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}