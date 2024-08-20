#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve(){
    int n, k, d;
    cin>>n>>k>>d;
    vector<int> arr(n);
    for(auto &it : arr)  cin>>it;

    int head = -1, tail = 0;
    int currS = 0, oddCnt = 0;
    int ans = -1e18;

    while(tail < n){
        while(head + 1 < n && (oddCnt + (arr[head+1]&1) <= k) && (currS + arr[head+1] <= d)){
            head++;
            currS+=arr[head];
            oddCnt+=(arr[head]&1);
        }

        if(head >= tail) ans = max(ans, currS);

        if(head < tail){
            tail++;
            head = tail-1;
        }else{
            currS-=arr[tail];
            oddCnt-=(arr[tail]&1);
            tail++;
        }
    }

    if(ans ==  -1e18) cout<<"IMPOSSIBLE"<<"\n";
    else cout<<ans<<"\n";
}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt; cin>>tt; while(tt--)
  solve();
}