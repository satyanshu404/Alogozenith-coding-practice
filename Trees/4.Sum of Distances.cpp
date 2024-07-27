#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int n;
vector<vector<int>> g;
vector<int> subtree;

void dfs(int node, int parent){
	
	for(auto v: g[node]){
		if (v == parent) continue;
		dfs(v, node);
		subtree[node] += subtree[v];
	}

	subtree[node] += 1;
}

void solve(){
	cin >> n;
	g.resize(n+1);
	subtree.assign(n+1, 0);

	for(int i = 0l; i < n-1; ++i){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1, 0);
	
	int total_dist = 0;
	for(int i = 0; i <=n; ++i){
		total_dist += subtree[i] * (n - subtree[i]);
	}

	cout << total_dist << endl;
	  

}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//   int tt; cin>>tt; while(tt--)
  solve();
}