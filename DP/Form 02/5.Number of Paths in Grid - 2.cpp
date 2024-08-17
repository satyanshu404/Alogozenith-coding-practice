#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int n, m, k;
int mod = 1e9+7;
vector<vector<int>> mat;
vector<vector<vector<int>>> dp;

int rec(int i, int j, int b){

    if(i < 0 or j < 0 or i >= n or j >=m)   return 0;

    if(i == 0 and j == 0){
        if(mat[i][j] == 0)
            return 1;
        else
            return (b > 0) ? 1: 0;
    }

    if(dp[i][j][b] != -1)
        return dp[i][j][b];

    if(mat[i][j] == 1){
        if(b <= 0)  return dp[i][j][b] =  0;
        else{
            return dp[i][j][b] = (rec(i-1, j, b-1)%mod + rec(i, j-1, b-1)%mod)%mod;
        }
    }

    int ans =  rec(i-1, j, b) + rec(i, j-1, b);

    return dp[i][j][b] = ans%mod;


}

void solve(){
    cin >> n >> m >> k;

    mat.assign(n, vector<int>(m, 0));
    dp.assign(n+1, vector<vector<int>>(m+1, vector<int>(k+1, -1)));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j)  cin >> mat[i][j];
    }

    cout << rec(n-1, m-1, k) << endl;

}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt; cin>>tt; while(tt--)
  solve();
}