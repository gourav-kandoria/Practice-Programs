#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
ll mod = 1000000007;

#define loop(n) for(int64_t i=0; i<n; i++)
#define loop1(a,b) for(int64_t i=a; i<=b; i++)

template <typename T>
void print(T a, T b, string end="\n") {
    for_each(a,b,[](auto & i){cout << i << " ";});
    cout << end;
}

void dfs(ll s, bool* arr, vector<vector<ll> >& vec, vector<ll> & topo) {
    for(auto a : vec[s]) {
        if(!arr[a]) {
            arr[a] = 1;
            dfs(a,arr,vec,topo);
        }
    }
    topo.pb(s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll v,e; cin >> v >> e;
    ll p,q; cin >> p >> q;
    vector<vector<ll> > vec(v);
    loop(e) {
        ll a,b;
        cin >> a >> b;
        vec[a].push_back(b);
    }
    vector<ll> topo;
    bool arr[v] = {false};
    loop(v) {
        if(!arr[i]) {
            arr[i] = 1;
            dfs(i,arr,vec,topo);
        }
    }
    reverse(topo.begin(),topo.end());
    unordered_map<ll,ll> find_index;

    loop(v) {
        find_index[topo[i]] = i;
    }

    ll index_p = find_index[p];
    ll index_q = find_index[q];
    ll sol[v] = {0};
    sol[index_p] = 1;
     
    loop1(index_p,index_q) {
        for(auto a : vec[topo[i]]) {
            ll ind = find_index[a];
            sol[ind]+=sol[i];
        }
    }
    cout << sol[index_q] << endl;
}