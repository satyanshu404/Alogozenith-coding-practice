
#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
// #define int long long

int dp[101][100100];
int n;
vector<int> arrs;

int rec(int i, int left){
   // pruning
   if(left < 0) return 0;
   //base case
   if(i == n){
        if(left == 0)   return 1;
        else    return 0;
   }

   // cache check
   if(dp[i][left] != -1)    return dp[i][left];

   // iterating through choices
   int ans = rec(i+1, left) or rec(i+1, left-arrs[i]);

   // save and return
   return dp[i][left] =  ans;
}

void generat(int i, int left, vector<int> &result){

    if(i == n){
        return;
    }

    if(rec(i+1, left))  generat(i+1, left, result);
    else{
        result.push_back(i);
        generat(i+1, left-arrs[i], result);
    }
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    // Write code here.
    memset(dp,-1,sizeof(dp));
    arrs = arr;
    n = arr.size();

    vector<vector<int>> results;
    for(int i = 0; i < queries.size(); ++i){
        vector<int> result;
        if(rec(0, queries[i])){
            generat(0, queries[i], result);
            if(result.size())   results.push_back(result);

        }else{
            result.push_back(-1);
            results.push_back(result);
        }
    }
    
    return results;
}


void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
