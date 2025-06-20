#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18
int32_t main(){
    int t;
    cin >> t;
    while(t--){
    int n;
    cin >> n;

    vector<pair<int,int>>a(n);
    vector<int>xs(n), ys(n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        a[i] = {x,y};
        xs[i] = x;
        ys[i] = y;        
    }
    if(n <= 2){
        cout << n << endl;
        continue;
    }
    sort(xs.begin(),xs.end());
    sort(ys.begin(),ys.end());
    int xmin1 = xs[0];
    int xmin2 = xs[1];
    int ymin1 = ys[0];
    int ymin2 = ys[1];
    int xmax1 = xs[n - 1];
    int xmax2 = xs[n - 2];
    int ymax1 = ys[n - 1];
    int ymax2 = ys[n - 2];
    int ans = INF;
    for(int i = 0; i < n; i++){
        auto [x,y] = a[i];
        
        int nxmin = (x == xmin1) ? xmin2 : xmin1;
        int nxmax = (x == xmax1) ? xmax2 : xmax1;
        int nymin = (y == ymin1) ? ymin2 : ymin1;
        int nymax = (y == ymax1) ? ymax2 : ymax1;
        int w = (nxmax - nxmin + 1) ;
        int h = (nymax - nymin + 1);
        int area = w * h;
        if(area == n - 1){
            ans = min(ans, min(((h + 1) * w), (w + 1) *h));
        }else{
            ans = min(ans, h * w);
        }
        
    }
    cout << ans << endl;
    }
}