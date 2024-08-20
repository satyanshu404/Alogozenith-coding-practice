#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    int arr[n];

    for(int i = 0; i < n; ++i)  cin >> arr[i];

    int tail = 0, head = -1;
    int ans = -1;
    unordered_map<int, int> ump;

    while(tail < n){
        while(head+1 < n and (ump[arr[head+1]] == 0)){
            head++; 
            ump[arr[head]]++;
        }

        ans = max(ans, head-tail+1);
        if(tail > head){
            tail++; head = tail-1;
        }else{
            ump[arr[tail]]--;
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