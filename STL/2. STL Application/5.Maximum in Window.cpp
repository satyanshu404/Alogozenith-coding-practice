#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

struct MonotoneDeque{
    deque<int> dq;

    void insert(int x){
        while(!(dq.empty()) and x > dq.back())    dq.pop_back();
        dq.push_back(x);
    }

    void remove(int x){
        if(!(dq.empty()) and dq.front() == x) dq.pop_front();
    }

    int get_max(){
        // for(auto it: dq){
        //     cout << it << " ";
        // }
        // cout << endl;
        return dq.front();
    }
};

void solve(){
    int n, k; cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; ++i)  cin >> arr[i];

    MonotoneDeque monodq;

    for(int i = 0; i < n; ++i){
        monodq.insert(arr[i]);
        
        if(i+1 >= k){
            cout <<  monodq.get_max()<< " ";
            monodq.remove(arr[i-k+1]);
        }
    }
    cout << endl;
}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt; cin>>tt; while(tt--)
  solve();
}