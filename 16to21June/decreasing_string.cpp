#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int k;
        cin >> k;
        int sz = s.length();
        while(k > sz){
            k -= sz;
            sz--;
        }
        int rem = s.length() - sz;
        stack<char>st;
        st.push(s[0]);
        for(int i = 1; i < s.length(); i++){
            while(rem && !st.empty() && st.top() > s[i]){
                st.pop();
                rem--;
            }
            st.push(s[i]);
        }
        while(st.size() > k){
            st.pop();
        }
        cout << st.top(); 
    }
}