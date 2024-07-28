#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int n, q;

struct UnionFind{
    vector<int> par, rank;

    UnionFind(int n){
        rank.assign(n, 0);
        par.assign(n, 0);
        for(int i = 0;i<n;++i){
            par[i] = i;
        }
    }

    int find(int x){
        if (par[x]==x)
            return x;

        return par[x] = find(par[x]);
    }

    void merge(int x, int y){
        int xx = find(x), yy = find(y);

        if(xx == yy) return;

        if(rank[xx] < rank[yy]){
            par[xx] = yy;
            rank[yy] += rank[xx];
        }else{
            par[yy] = xx;
            rank[xx] += rank[yy];
        }
    }

}; 

void solve(){
    cin >> n >> q;

    UnionFind uf(n);

    while(q--){
        int x, a, b; cin >> x >> a >> b;

        if(x == 0){
            uf.merge(a, b);
        }else{
            if(uf.find(a) == uf.find(b))
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }

}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//   int tt; cin>>tt; while(tt--)
  solve();
}