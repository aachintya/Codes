#include<bits/stdc++.h>
using namespace std;
#define rep(i,k,n)     for(ll i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define debarr(arr) for(ll xxx = 0; xxx < arr.size(); xxx++) cout <<  arr[xxx] << ' '; cout<< endl;
#define deb(x)         cout << #x << "=" << x << endl
#define deb2(z, x, y)  cout << #z ": (" << x << ", " << y << ")\n";
#define ll    long long
#define pb    push_back
#define mp    make_pair
#define F    first
#define S    second
#define all(x)        x.begin(), x.end()
#define clr(x)        memset(x, 0, sizeof(x))
#define sz(x) (int) (x).size()
#define sortall(x)    sort(all(x))
#define tr(it, a)    for(auto it = a.begin(); it != a.end(); it++)
#define PI    3.1415926535897932384626
typedef pair<int, int>    pii;
typedef pair<ll, ll>    pl;
typedef vector<int>        vi;
typedef vector<ll>        vl;
typedef vector<pii>        vpii;
typedef vector<pl>        vpl;
typedef vector<vi>        vvi;
typedef vector<vl>        vvl;


const int mod = 1000000007;
const int N = 1e6 + 7, M = N;
//=======================


void solve() {
    int n,m;
    cin >> n >> m; 
    vector<int>a(n);
    int bound = N;
    for(int x = 0; x < n; ++x){ 
        cin >> a[x];
        bound = max(bound,a[x]);
    }
    if(n > m) cout << "0\n";
    else{
        ll product = 1;
        for(int x = 0; x < n; ++x){ 
            for(int y = x + 1; y < n; ++y){ 
                int mul = a[x] - a[y];
                if(mul < 0){ 
                    mul += m;
                }
                product *= mul;
                product %= m;
            }
        }
        cout << product << "\n";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
