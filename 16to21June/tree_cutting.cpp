#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int res;
int x;

int dfs(int curr, int parent) {
    int sz = 1;
    for (int child : adj[curr]) {
        if (child != parent) {
            sz += dfs(child, curr);
        }
    }
    if (sz >= x && curr != 0) {
        res++;
        return 0;
    }
    return sz;
}

bool check(int k) {
    res = 0;
    int d = dfs(0, -1);
    return (res > k || (d >= x && res == k));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        adj.assign(n, {});
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--; 
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int lo = 1, hi = n, ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            x = mid;
            if (check(k)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
