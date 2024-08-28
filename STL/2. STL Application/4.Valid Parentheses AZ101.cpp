#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve(){
    string s; cin >> s;

    int n = s.length();

    stack<char> st;

    for(int i = 0; i < n; ++i){
        if(s[i] == '(') st.push(s[i]);
        else{
            if(!(st.empty()) and st.top() == '(') st.pop();
            else    st.push(s[i]);
        }
    }


    cout << st.size() << endl;

}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt; cin>>tt; while(tt--)
  solve();
}