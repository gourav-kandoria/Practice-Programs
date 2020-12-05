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

int main() {
  // fast_io
  ll n; cin >> n;
  vector< vector<ll> > graph(n);

  loop(i,n-1) {
    ll s,d; 
    cin >> s >> d;
    graph[s-1].push_back(d-1);
    graph[d-1].push_back(s-1);
  }

  ll x; cin >> x;

  vector<bool> visited(n,false);

  ll count=0;
  queue<pll> que; que.push({0,1}); 
  visited[0] = true;
  while(!que.empty()) {

    auto a = que.front(); que.pop();
    if(a.second==x) count++;
    for(auto d : graph[a.first]) {
      if(!visited[d]) {
        visited[d] = true;
        que.push({d, a.second+1});
      }
    }
  }

  cout << count << "\n";
}