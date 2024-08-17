#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define endl '\n'

int n, k;
int arr[100100];
int dp[100100];

int rec(int lvl){

    //base case
    if (lvl==0) 
        return 0;

    // cache check
    if(dp[lvl] != -1) return dp[lvl];

    // transitions
    int ans = INT_MAX, best_idx;
    for(int trans = max(0, lvl-k); trans < lvl; ++trans){
        ans = min(rec(trans) + abs(arr[lvl] - arr[trans]), ans);
    }
    // save and return
    return  dp[lvl] = ans;
}

void solve(){
    cin >> n >> k;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    memset(dp, -1, sizeof(dp));

    int ans = rec(n-1);

    cout << ans << endl;


}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//   int tt; cin>>tt; while(tt--)
  solve();
}