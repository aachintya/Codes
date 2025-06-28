#include <bits/stdc++.h>
using namespace std;
struct DSU {
    vector<int> p;
    DSU(int n): p(n+1,-1){}
    int find(int x){ return p[x]<0?x:p[x]=find(p[x]); }
    void unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return;
        if(p[a]>p[b]) swap(a,b);
        p[a]+=p[b];
        p[b]=a;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        int n,e,q;
        cin>>n>>e>>q;
        DSU dsu(n);
        vector<tuple<int,int,int>> edges;
        edges.reserve(e);
        for(int i=0,u,v,w;i<e;i++){
            cin>>u>>v>>w;
            edges.emplace_back(u,v,w);
            dsu.unite(u,v);
        }
        vector<int> comp_and(n+1, INT_MAX);
        for(auto &ed:edges){
            int u,v,w;
            tie(u,v,w)=ed;
            comp_and[dsu.find(u)] &= w;
        }
        while(q--){
            int u,v;
            cin>>u>>v;
            int pu=dsu.find(u), pv=dsu.find(v);
            if(pu!=pv) {
                cout<<-1<<" ";
            }else{
                cout<<comp_and[pu]<<" ";
            }
        }
        cout << endl;
    }
    return 0;
}