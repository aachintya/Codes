#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        int c0 = 0, c1 = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                c0++;
            }else{
                c1++;
            }
        }
        if(k >= n/2 - min(c0,c1) && k <= c0/2 + c1/2){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}
