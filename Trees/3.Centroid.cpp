#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int n;
vector<vector<int>> g;
vector<int> subt;
vector<int> par;
int point;

void find_subtree(int node, int parent){
	par[node] = parent;
    for(auto v: g[node]){
		if (v == parent) continue;
		find_subtree(v, node);
		subt[node] += subt[v];
	}
	subt[node] += 1;
}

void centriod(int node, int parent){
  subt.assign(n+1, 0);
  find_subtree(node, parent);

  for(auto v: g[node]){
	if(node == parent) continue;
	if(subt[v] > n/2){
		centriod(v, node);
        return;
	}
  }
  point = node;
}

void solve(){
  cin >> n;
  g.resize(n+1);
  subt.assign(n+1, 0);
  par.assign(n+1, 0);

  for(int i = 0; i < n-1; ++i){
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  centriod(1, 0);

  cout << point << endl;


}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // int tt; cin>>tt; while(tt--)
  solve();
}