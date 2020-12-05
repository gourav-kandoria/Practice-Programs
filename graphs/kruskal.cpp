#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
#define pll pair<ll,ll>
#define pii pair<int32_t,int32_t>
#define loop(i,n) for(int64_t i=0; i<n; i++)
#define loop1(i,a,b) for(int64_t i=a; i<=b; i++)
#define rloop(i,n) for(int64_t i=n-1; i>=0; i--) 
#define rloop1(i,a,b) for(int64_t i=a; i>=b; i--) 
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define print(val) cout << #val << ": " << val << "\n";
#define print_c(a) cout<<#a<<": ";for(auto it=begin(a);it!=end(a);it++)cout<<*it<<" ";cout<<"\n";
#define fill(c,v) fill(begin(c),end(c),v);
template <typename T> T flip(T val) {reverse(begin(val),end(val)); return val;}

class edge {
public:
  ll s,d,w;
  edge(ll s,ll d,ll w) {
    this->s = s; this->d= d; this->w = w;
  };
};

pll find(ll node, vector<pll> & vec) {
  if(vec[node].first == node) return vec[node];
  return find(vec[node].first, vec);
}

void uniun(pll a, pll b, vector<pll> & vec) {
  if(a.second < b.second) {
    vec[a.first].first = b.first;
    vec[b.first].second+=vec[a.first].second;
  }
  else {
    vec[b.first].first = a.first;
    vec[a.first].second+=vec[b.first].second;
  }
}

int main() {
  fast_io
  ll n,m; cin >> n >> m;
  // vector< vector<pll> > vec(n);
  vector<edge> edges;

  loop(i,m) {
    ll a, b, w; cin >> a >> b >> w;
    edges.push_back(edge(a,b,w));
  }

  sort(edges.begin(),edges.end(),[](edge a, edge b) {
    return a.w < b.w;
  });

  // array for storing parents
  vector< pll > paAndSize(n);
  loop(i,n) paAndSize[i] = {i,1};

  ll sum=0;
  loop(i,m) {
    auto e = edges[i];
    pll pas = find(e.s, paAndSize);
    pll pad = find(e.d, paAndSize);
    if(pas.first!=pad.first) {
      sum+=e.w;
      uniun(pas, pad, paAndSize);
    }
  }
  cout << sum << "\n";
}