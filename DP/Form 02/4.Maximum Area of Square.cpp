#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int n, m;
vector<vector<int>> mat, dp;

int rec(int i, int j){

    if(i < 0 or j < 0 or i >= n or j >= m)
        return 1e9;

    if(i == 0 or j == 0){
        if(mat[i][j]==1)    return 1;
        else 0;
    }

    if(dp[i][j] != -1)
        return dp[i][j];

    if (mat[i][j] == 0){
        return dp[i][j] = 0;
    }
    
    int ans = min(rec(i-1, j-1), rec(i-1, j));
    ans = min(ans, rec(i, j-1));

    return dp[i][j] = ans+1;
}

void solve(){
    cin >> n >> m;
    mat.assign(n, vector<int>(m, 0));
    dp.assign(n+1, vector<int>(m+1, -1));

    for(int i=0; i<n;++i){
        for(int j=0;j<m;++j){
            cin >> mat[i][j];
        }
    }

    int ans = -1;
    for(int i = 0;i<n;++i){
        for(int j=0;j<m;++j){
            ans = max(ans, rec(i, j));
        }
    }

    cout << ans * ans << endl;

}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt; cin>>tt; while(tt--)
  solve();
}