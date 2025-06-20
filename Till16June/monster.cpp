#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define INF 1e18
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>>grid(n, vector<char>(m));
    vector<vector<int>>mon_time(n, vector<int>(m, INF));
    queue<pair<int,int>>q;
    int startx, starty;
    for(int i = 0; i < n; i++){
        for(int j = 0; j  < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'M'){
                q.push({i,j});
                mon_time[i][j] = 0;
            }
            if(grid[i][j] == 'A'){
                startx = i;
                starty = j;
            }
        }
    }
    vector<pair<int,int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
    string s = "RDLU";
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for(auto [dx,dy] : dir){
            int r = x + dx;
            int c = y + dy;
            if(r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != '#'){
                if(mon_time[r][c] > mon_time[x][y] + 1){
                    mon_time[r][c] = mon_time[x][y] + 1;
                    q.push({r,c});
                }
            }
        }
    }
    queue<pair<int,int>>qa;

    qa.push({startx, starty});
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1, -1}));
    vector<vector<int>>time(n,vector<int>(m,INF));
    time[startx][starty] = 0;
    bool flag = false;
    pair<int,int> escape = {-1, -1};
    while(!qa.empty()){
        auto [x,y] = qa.front();
        qa.pop();
        if(x == 0 || x == n - 1 || y == 0 || y == m - 1){
            flag = true;
            escape = {x, y};
            break;
        }
        for(int k = 0; k < 4; k++){
            int dx = dir[k].first, dy = dir[k].second;
            int r = x + dx;
            int c = y + dy;
            if(r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != '#' && mon_time[r][c] > time[x][y] + 1 && time[r][c] == INF){
                time[r][c] = time[x][y] + 1;
                parent[r][c] = {x,y};
                qa.push({r,c});
            }
        }
    }
    if(flag){
        cout << "YES\n";
        string path = "";
        pair<int,int> curr = escape;
        while(curr != make_pair(startx, starty)){
            auto [px,py] = parent[curr.first][curr.second];
            int dx = curr.first - px;
            int dy = curr.second - py;
            for(int k = 0; k < 4; k++){
                if(dir[k].first == dx && dir[k].second == dy){
                    path += s[k];
                    break;
                }
            }
            curr = {px, py};
        }
        reverse(path.begin(), path.end());
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