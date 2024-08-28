#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.first + a.second > b.first + b.second;
}

void solve(){
    int n; cin >> n; 
    int a[n], b[n];

    for(int i = 0; i < n; ++i)  cin >> a[i];
    for(int i = 0; i < n; ++i)  cin >> b[i];

    vector<pair<int, int>> arr(n);
    for(int i = 0; i<n; ++i)    arr[i] = {a[i], b[i]};

    sort(arr.begin(), arr.end(), cmp); 

    int score_a = 0, score_b = 0;
    for(int i = 0; i < n; ++i){
        if(!(i&1))  score_a += arr[i].first;
        else    score_b += arr[i].second;
    }

    if(score_a == score_b)  cout << "Tie" << endl;
    else if(score_a > score_b)  cout << "Alice" << endl;
    else    cout << "Bob" << endl;

}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt; cin>>tt; while(tt--)
  solve();
}