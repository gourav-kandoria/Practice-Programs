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
  edge(ll s, ll d, ll w) {
    this->s = s; this->d = d; this->w = w;
  };
};

class compar {
  public:
  bool operator()(const edge & a, const edge & b) {
    return a.w > b.w;
  }
};

vector< vector<pll> > graph;
vector<bool> nodes;
priority_queue<edge, vector<edge>, compar> que;

int main() {
  fast_io
  ll n,m; cin >> n >> m;
  graph.resize(n);
  loop(i,m) {
    ll s,d,w; cin >> s >> d >> w; 
    graph[s-1].push_back({d-1,w});
    graph[d-1].push_back({s-1,w});
  }
  nodes.resize(n); loop(i,n) nodes[i]=0;
  nodes[0] = 1;
  for(auto d : graph[0]) {
    que.push(edge(0,d.first,d.second));
  }
  vector<edge> results; 

  while(!que.empty()){
    edge t = que.top();
    que.pop();
    if(nodes[t.d]==1) continue;
    nodes[t.d] = 1;
    results.push_back(t);
    for(auto d : graph[t.d]) {
      if(nodes[d.first]==0) {
        que.push(edge(t.d,d.first,d.second));
      }
    }
  }

  ll sum=0; loop(i,results.size()) sum+=results[i].w;
  cout << sum << "\n";
}