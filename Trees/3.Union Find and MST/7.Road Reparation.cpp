#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int n, m;
int cost = 0;
vector<vector<int>> edgelist;

struct UnionFind{
    vector<int> par, rank;
    int cc;

    UnionFind(int n){
        par.assign(n+1, 0);
        rank.assign(n+1, 0);
        for(int i = 1; i <=n; ++i) par[i] = i;
        cc = n;
    }

    int find(int x){
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    bool merge(int x, int y){
        int xroot = find(x), yroot = find(y);

        if(xroot == yroot)  return false;
        cc--;

        if(rank[xroot] < rank[yroot]){
            rank[yroot] += rank[xroot];
            par[xroot] = yroot;
        }else{
            rank[xroot] += rank[yroot];
            par[yroot] = xroot;
        }

        return true;
    }
};

void solve(){
    cin >> n >> m;
    edgelist.resize(m);

    UnionFind uf(n);

    for(int i = 0; i < m; ++i){
        int a, b, c; cin >> a >> b >> c;
        edgelist[i] = {c, a, b};
    }

    sort(edgelist.begin(), edgelist.end());

    for(int i = 0; i < m; ++i){
        int u = edgelist[i][1], v = edgelist[i][2];
        if(uf.merge(u, v)){
            cost += edgelist[i][0];
        }
    }
    
    if(uf.cc != 1){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    cout << cost << endl;

}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//   int tt; cin>>tt; while(tt--)
  solve();
}