#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define endl '\n'

int n;
int arr[510];
int dp[510][510];

int rec(int l, int r){
    if(l == r)  return 0;

    if(dp[l][r] != -1)  return dp[l][r];

    int total = 0;
    int sum = 0;
    int ans = 1e9;

    for(int i = l; i <= r; ++i)     total += arr[i];

    for(int mid = l; mid < r; ++mid){
        sum += arr[mid];
        ans = min(ans, rec(l, mid) + rec(mid+1, r) + (sum%100)*((total-sum)%100));
    }

    return dp[l][r] = ans;
}

void solve(){
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));

    cout << rec(0, n-1) << endl;

}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//   int tt; cin>>tt; while(tt--)
  solve();
}