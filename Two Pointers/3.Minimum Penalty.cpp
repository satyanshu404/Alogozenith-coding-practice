#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve(){
    int n, k; cin >> n >> k;
    int arr[n];

    for(int i = 0; i < n; ++i)  cin >> arr[i];

    int ans = 1e9, len = 0, distinct = 0;
    int tail = 0, head = -1;
    unordered_map<int, int> mp;

    while(tail<n){ 
        while(head+1<n and (head-tail+1) < k){
            head++;
            if(mp[arr[head]]==0)   distinct++;

            mp[arr[head]]++; 
        }

        if(head-tail+1 != k){
            cout << ans << endl;
            return;
        }

        ans = min(ans, distinct);

        if(tail>head){
            tail++;
            head = tail-1;
        }else{
            mp[arr[tail]]--;
            if(mp[arr[tail]] == 0)  distinct--;
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