#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
    
    int n;
    cin >> n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<int>deg(n+1);
    for(int i = 1;i < n; i++){
        int x,y;
        cin >> x >> y;
        deg[x]++;
        deg[y]++;
    }
    priority_queue<int>pq;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < deg[i]; j++){
            pq.push(a[i]);
        }
    }
    long long sum = accumulate(a.begin()+1,a.end(),0LL);
    cout << sum << " ";
    for(int i = 2; i <= n - 1; i++){
        sum += pq.top();
        pq.pop();
        cout << sum << " ";
    }
    cout << endl;
    }
    return 0;
}