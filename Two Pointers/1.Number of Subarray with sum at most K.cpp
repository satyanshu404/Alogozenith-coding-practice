#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int n, k;
int arr[100100];

void solve(){
    cin >> n >> k;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    int head = -1, tail = 0;
    int sum = 0;
    int ans = 0;

    while(tail < n){
        while(head+1< n && (sum + arr[head+1]) <= k){
            head++;
            sum += arr[head];
        }
        ans += (head-tail+1);
        
        if(tail>head){
            tail++;
            head = tail-1;
        }else{
            sum -= arr[tail];
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