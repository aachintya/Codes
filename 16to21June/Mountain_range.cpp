#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    stack<int>st;
    vector<int>nge(n,-1);
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && a[st.top()] <= a[i]){
            st.pop();
        }
        if(!st.empty()){
            nge[i] = st.top();
        }
        st.push(i);
    }
    int best = 1;
    for(int i = 0; i < a.size(); i++){
    
        if(nge[i] != -1){
            best = max(best, nge[i] - i);
        }else{
            best = max(best, n - i);
        }
    }
    cout << best << endl;
}