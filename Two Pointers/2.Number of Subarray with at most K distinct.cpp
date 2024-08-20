#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve(){
    int n, k; cin >> n >> k;
    
    int arr[n];
    for(int i = 0; i < n; ++i)  cin >> arr[i];

    int tail = 0, head = -1;
    int ans = 0, distnt = 0;
    map<int, int> mp;

    while(tail < n){
        while(head+1<n and (distnt < k or mp[arr[head+1]] != 0)){
            head++;
            if(mp[arr[head]] == 0)  distnt++;
            mp[arr[head]]++;
        }

        ans += head -tail+1;
        if(tail>head){
            tail++;
            head=tail-1;
        }else{
            mp[arr[tail]]--;
            if(mp[arr[tail]]==0)    distnt--;
            tail++;
        }
    }
    cout << ans << endl;

}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt; cin>>tt; while(tt--)
  solve();
}