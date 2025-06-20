#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    int a = -1, b = -1, c = -1, d = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                a = i;
                b = j;
            }
            if(grid[i][j] == 'B'){
                c = i;
                d = j;
            }
        }
    }
    
    if(a == -1 || b == -1 || c == -1 || d == -1) {
        cout << "NO\n";
        return;
    }
    
    vector<pair<int,int>>dir = {{-1,0},{0,-1},{1,0},{0,1}};
    queue<pair<int,int>>q;
    q.push({a,b});
    int flag = 0;
    string s = "ULDR";
 
    vector<vector<int>>vis(n, vector<int>(m,0));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
    vis[a][b] = 1;
    
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        if(x == c && y == d){
            flag = 1;
            break;
        }
        for(auto [dx,dy] : dir){
            int r = x + dx;
            int c2 = y + dy;
            if(r >= 0 && r < n && c2 >= 0 && c2 < m && grid[r][c2] != '#' && vis[r][c2] == 0){
                vis[r][c2] = 1;
                q.push({r,c2});
                parent[r][c2] = {x,y};
            }
        }
    }
    
    if(flag){
        string path = "";
        pair<int,int> curr = {c,d};
        pair<int,int> start = {a,b};
        while(curr != start){
            pair<int,int> par = parent[curr.first][curr.second];
            int dx = curr.first - par.first;
            int dy = curr.second - par.second;
            for(int idx = 0; idx < 4; idx++){
                if(dx == dir[idx].first && dy == dir[idx].second){
                    path.push_back(s[idx]);
                    break;
                }
            }
            curr = par;
        }
        cout << "YES\n";
        cout << path.length() << endl;
        reverse(path.begin(), path.end());
        cout << path << endl;
    }else{
        cout << "NO\n";
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
