#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    int arr[n];

    for(int i = 0; i < n; ++i)  cin >> arr[i];

    unordered_set<int> s;
    for(int i = 0; i < n; ++i)  s.insert(arr[i]);

    int t_distinct = s.size(), distinct = 0; 
    int tail = 0, head = -1;
    int ans = 1e9;
    unordered_map<int, int> ump;

    while(tail < n){
        while(head+1< n and (distinct < t_distinct )){
            head++;
            if(ump[arr[head]] == 0) distinct++;
            ump[arr[head]]++;
        }

        if(distinct == t_distinct)
            ans = min(ans, head-tail+1);
        if(tail>head){
            tail++; head = tail-1;
        }else{
            ump[arr[tail]]--;
            if(ump[arr[tail]] == 0) distinct--;
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