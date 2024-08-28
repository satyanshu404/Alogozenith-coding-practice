#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

struct Bag{
    multiset<int> topk, rest;
    int k, sum = 0;
    Bag(int k) : k(k) {}

    void insert(int x){
        topk.insert(x);
        sum += x;
        if(topk.size() > k){
            auto it = topk.begin();
            sum -= *it;
            rest.insert(*it);
            topk.erase(topk.find(*it));
        }
    }

    void remove(int x) {
        if(!(topk.empty())){
            auto it = topk.find(x);
            if(it != topk.end()){
                sum -= *it; topk.erase(it);
                if(!(rest.empty())){
                    auto it = rest.rbegin();
                    topk.insert(*it); sum += *it;
                    rest.erase(rest.find(*it));
                }
            }
        }else if(!(rest.empty())){
            auto it = rest.find(x);
            if(it != rest.end()){rest.erase(it);}
        }
    }

    int tok_k_sum(){
        return sum;
    }

};

void solve(){
    int q, k; cin >> q >> k;

    Bag bag(k);

    while(q--){
        int n; cin >> n;
        if(n == 1){
            int x; cin >> x;
            bag.insert(x);
        }else if(n == 2){
            int x; cin >> x;
            bag.remove(x);
        }else{
            char tmp; cin >> tmp;
            cout << bag.tok_k_sum() << endl;
        }
    }


}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//   int tt; cin>>tt; while(tt--)
  solve();
}