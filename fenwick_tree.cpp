#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

class FenwickTree {
private:
    int n;
    vector<int> bit;
    int maxP;
public:
    FenwickTree(int n) {
        this->n = n;
        bit.resize(n + 1, 0);
        int p = 1;
        while (p * 2 <= n) p *= 2;
        maxP = p;
    }
    void update(int i, int delta) {
        while (i <= n) {
            bit[i] += delta;
            i += (i & -i);
        }
    }
    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }
    int findkth(int k) {
        int idx = 0;
        int bitmask = maxP;
        while (bitmask > 0) {
            int next = idx + bitmask;
            if (next <= n && bit[next] < k) {
                idx = next;
                k -= bit[next];
            }
            bitmask >>= 1;
        }
        return idx + 1;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    auto get = [&](int x) {
        return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
    };

    int median = (k + 1) / 2;
    FenwickTree fen(b.size());

    for(int i = 0; i < k; i++) {
        fen.update(get(a[i]), 1);
    }

    vector<int> ans;

    int j = fen.findkth(median);
    ans.push_back(b[j - 1]);

    for(int i = k; i < n; i++) {
        fen.update(get(a[i - k]), -1);
        fen.update(get(a[i]), 1);
        int j = fen.findkth(median);
        ans.push_back(b[j - 1]);
    }

    for(int x : ans) cout << x << ' ';
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    while(t--) solve();

    return 0;
}
