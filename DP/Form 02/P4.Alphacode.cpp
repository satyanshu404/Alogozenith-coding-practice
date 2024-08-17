#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define endl '\n'

string s;
int dp[5010];

int rec(int lvl){
	//pruning
	if (lvl <= 0) return 1;

	//cache check
	if(dp[lvl] != -1)	return dp[lvl];

	// transitions
	int ans = 0;
	if (s[lvl] != '0')
		ans += rec(lvl-1);
	if ((s[lvl-1] == '1' or s[lvl-1] == '2') and s[lvl] <= '6'){
		ans += rec(lvl-2);
	}

	//save and return
	return dp[lvl] = ans;
}

void solve(){
    
    cin >> s;

	if(s[0] == '0'){
		cout << 0 << endl;
		return;
	}

	memset(dp, -1, sizeof(dp));

    cout << rec(s.size()-1) << endl;

}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//   int tt; cin>>tt; while(tt--)
  solve();
}