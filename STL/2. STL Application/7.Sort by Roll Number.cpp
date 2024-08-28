#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;

    multiset<pair<int, string>> ms;

    for(int i = 0; i < n; ++i){
        string s; cin >> s;
        int tmp; cin >> tmp;
        ms.insert({tmp, s});
    }

    for(auto it: ms)    
        cout << it.second << " " << it.first << endl;

}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt; cin>>tt; while(tt--)
  solve();
}