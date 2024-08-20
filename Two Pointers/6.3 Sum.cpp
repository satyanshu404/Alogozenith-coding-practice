#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve(){
    int n, target; cin >> n >> target;
    int arr[n];

    for(int i = 0; i < n; ++i)  cin >> arr[i];

    sort(arr, arr+n);

    int ans = 1e18;

    for(int j = 0; j < n; ++j){
        int i = 0, k = n-1;
        while(i<j and j<k){
            int sum = arr[i] + arr[j] + arr[k]; 
            ans = min(ans, abs(sum - target));
            if(sum < target)    ++i;
            else   --k;
        }
    }

    cout << ans << endl;

}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt; cin>>tt; while(tt--)
  solve();
}