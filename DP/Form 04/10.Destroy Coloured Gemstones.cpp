#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int n;
int dp1[110][110], dp2[110];
int arr[110];

int rec1(int l, int r){
    
    if(l>=r)    return 1;

    return rec1(l+1, r-1) and arr[l] == arr[r];
}

int rec2(int lvl){
    if(lvl == -1)   return 0;

    int ans = 1e9;
    for(int mid=-1; mid<lvl; ++mid){
        if(rec1(mid+1, lvl)) 
            ans = min(ans, rec2(mid) + 1);
    }

    return ans;
}

void solve(){
    cin >> n;
    for(int i =0;i<n;++i)   cin >> arr[i];

    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));

    cout << rec2(n-1) << endl;

}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt; cin>>tt; while(tt--)
  solve();
}