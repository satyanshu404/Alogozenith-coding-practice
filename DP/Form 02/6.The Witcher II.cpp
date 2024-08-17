#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int n, m;
vector<vector<int>> mat, dp, check;

int rec(int i, int j){

    if (i < 0 or j < 0 or i >= n or j >=m )   return 1e9;

    if(i == n-1 and j == m-1){
        return max(1LL*1, 1-mat[i][j]);
    }

    int ans = max(1LL*1, min(rec(i+1, j), rec(i, j+1))) - mat[i][j];

    return ans;

}

void solve(){
    cin >> n >> m;

    mat.assign(n, vector<int>(m, 0));
    dp.assign(n+1, vector<int>(m+1, 0));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> mat[i][j];
            // mat[i][j] *= -1;
        }
    }

    int ans = rec(0, 0);
    cout << ans << endl;



}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt; cin>>tt; while(tt--)
  solve();
}