#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define F first
#define S second
using state = pair<int, int>;

int n, m, q;
vector<vector<int>> edges;
vector<state> queries;
vector<int> ans;

struct UnionFind{
    vector<int> par, rank;
    int cc;

    UnionFind(int x){
        par.assign(x+1, 0);
        rank.assign(x+1, 0);
        cc = x;

        for(int i = 1; i <= x; ++i) par[i] = i;
    }

    int find(int x){
        if (x == par[x])
            return x;
        return par[x] = find(par[x]);
    }

    void merge(int x, int y){
        int xroot = find(x), yroot = find(y);

        if (xroot == yroot) return;
        cc--;

        if(rank[xroot] < rank[yroot]){
            par[xroot] = yroot;
            rank[yroot] += rank[xroot];
        }else{
            par[yroot] = xroot;
            rank[xroot] += rank[yroot];
        }
    }

};

void solve(){
    cin >> n >> m >> q;

    UnionFind uf(n);
    edges.resize(m + 1);

    for(int i = 1; i <= m; ++i){
        int u, v; cin >> u >> v;
        edges[i] = {u, v, 1};  // 1 means that edge is being considered
    }  

    while(q--){
        int x, a; cin >> x;

        if(x == 1){
            cin >> a;
            queries.push_back({x, a});
            edges[a][2] = 0;  
        }else{
            queries.push_back({x, -1});
        }
    }


    // make graph
    for(auto e: edges){
        if(e.size() == 0) continue;
        int u = e[0], v = e[1];
        if (e[2]){
            uf.merge(u, v);
        }
    }

    // for each query in reverse oder
    for (auto it = queries.rbegin(); it != queries.rend(); ++it) {
        int x = (*it).F, a = (*it).S;

        if (x == 2){
            ans.push_back(uf.cc);
        }else{
            int u = edges[a][0], v = edges[a][1];
            uf.merge(u, v);
        }
    }

    reverse(ans.begin(), ans.end());

    for(auto ele: ans){
        cout << ele << endl;
    }

}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//   int tt; cin>>tt; while(tt--)
  solve();
}