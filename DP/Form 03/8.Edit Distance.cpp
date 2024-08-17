#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

string s1, s2;
int n, m;

int dp[501][501];

int rec(int i, int j){
    if(i ==n)
        return m-j;
    if(j ==m)
        return n-i;
    
    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = 1e9;
    
    if(s1[i]==s2[j])    ans = min(ans, rec(i+1, j+1));
    ans = min(ans, 1+rec(i+1, j+1));
    ans = min(ans, 1+rec(i+1, j));
    ans = min(ans, 1+rec(i, j+1));

    return dp[i][j] = ans;
}

void solve(){
    cin >> s1 >> s2;
    n = s1.length();
    m = s2.length();

    memset(dp, -1, sizeof(dp));

    cout << rec(0, 0) << endl;

}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//   int tt; cin>>tt; while(tt--)
  solve();
}