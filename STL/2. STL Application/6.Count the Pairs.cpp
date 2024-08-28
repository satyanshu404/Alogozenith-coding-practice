#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve(){
    int n, k; cin >> n >> k;
    int arr[n];
    multiset<int> st;

    for(int i = 0; i < n; ++i){
        cin >> arr[i]; 
        st.insert(arr[i]);
    }
    sort(arr, arr+n);
    int count = 0;
    for(int i = 0; i < n; ++i){
        count += upper_bound(arr, arr+n, k-arr[i])- arr;
        // if two times the arr[i] is less than or equal to k then remove the instance of ith position
        if(arr[i] <= k - arr[i])    count--;    
    }

    cout << count << endl;

}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt; cin>>tt; while(tt--)
  solve();
}