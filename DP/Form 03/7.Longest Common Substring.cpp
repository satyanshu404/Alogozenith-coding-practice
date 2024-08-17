#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

string s1, s2;
int n, m;
vector<vector<int>> dp;

int rec(int l1, int l2){
    if(l1 >= n or l2 >= m) return 0;

    if(dp[l1][l2] != -1)
        return dp[l1][l2];

    int ans = 0;
    if(s1[l1] == s2[l2])    ans = max(ans, rec(l1+1, l2+1) + 1);

    return dp[l1][l2] = ans;
}

void solve(){
    cin >> s1 >> s2;
    n = s1.length();
    m = s2.length();

    dp.assign(n+1, vector<int>(m+1, -1));

    int maxi = -1e9;

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            maxi = max(maxi, rec(i, j));
        }
    }

    cout << maxi << endl;
}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt; cin>>tt; while(tt--)
  solve();
}