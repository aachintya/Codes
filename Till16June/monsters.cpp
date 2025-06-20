#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define INF 1e18
#define F first
#define S second
void solve() {
    int n,m;
    cin >> n >> m;
    pair<int,int>start;
    vector<vector<char>>grid(n,vector<char>(m));
    vector<vector<int>>mon_dist(n, vector<int>(m, INF));
    queue<pair<int,int>>q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                start.F = i;
                start.S = j;
            }
            if(grid[i][j] == 'M'){
                q.push({i,j});
                mon_dist[i][j] = 0;
            }
        }
    }
    vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    // DRUL
    string s = "DRUL";
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for(auto [dx,dy] : dir){
            int r = x + dx;
            int c = y + dy;
            if(r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != '#'){
                if(mon_dist[r][c] > mon_dist[x][y] + 1){
                    mon_dist[r][c] = mon_dist[x][y] + 1;
                    q.push({r,c});
                }
            }
        }
    }

    vector<vector<int>>a_time(n, vector<int>(m,INF));
    vector<vector<pair<int,int>>>parent(n, vector<pair<int,int>>(m, {-1,-1}));
    queue<pair<int,int>>qa;
    pair<int,int> curr = {-1,-1};
    int flag = 0;
    qa.push({start.F, start.S});
    a_time[start.F][start.S] = 0; 
    while(!qa.empty()){ 
        auto [x,y] = qa.front();
        qa.pop();
        if(x == 0 || x == n - 1 || y == 0 || y == m - 1){
            flag = 1;
            curr = {x,y};
            break;
        }
        for(auto [dx,dy] : dir){
            int r = x + dx;
            int c = y + dy;
            if(r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != '#' && a_time[r][c] == INF && mon_dist[r][c] > a_time[x][y] + 1){
                a_time[r][c] = a_time[x][y] + 1;
                parent[r][c] = {x,y};
                qa.push({r,c}); 
            }
        }
    }
    if(flag){
        cout << "YES\n";
        string s = "DRUL";
        string path = "";
        while(curr != start){
            auto par =  parent[curr.F][curr.S];
            int dx = curr.F - par.F;
            int dy = curr.S - par.S;
            for(int k = 0; k < 4; k++){
                auto [i,j] = dir[k];
                if(i == dx && j == dy){
                    path += s[k];
                    break;
                }
            }
            curr = par;
        }
        reverse(path.begin(),path.end());
        cout << path.length() << endl;
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