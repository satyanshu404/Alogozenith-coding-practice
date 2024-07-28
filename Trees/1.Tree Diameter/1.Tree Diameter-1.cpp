#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

vector<vector<int>> g;
vector<int> depth, par;
int n;

void dfs(int node, int parent, int level){
    par[node] = parent;
    depth[node] = level;

    for(auto v: g[node]){
        if (v != parent){
            dfs(v, node, level+1);
        }
    }
}

void solve(){
    cin >> n;
    g.resize(n+1);
    depth.assign(n+1, 0);
    par.assign(n+1, 0);

    for(int i = 0; i < n-1; ++i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0, 0);

    int max_node = -1, max_dist = -1;
    for(int i = 1; i <= n; ++i){
        if(depth[i] > max_dist){
            max_dist = depth[i];
            max_node = i;
        }
    }

    dfs(max_node, 0, 0);
    int final_dist = -1;
    for(int i = 1; i <= n; ++i){
        final_dist = max(depth[i], final_dist);
    }

    cout << final_dist << endl;


}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//   int tt; cin>>tt; while(tt--)
  solve();
}