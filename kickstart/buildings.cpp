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
  fast_io
  ll t=1; 
  cin >> t;
  loop1(tc,1,t) {
    ll n,a,b,c; cin >> n >> a >> b >> c;
    vector<ll> v1; 
    vector<ll> v2;
    vector<ll> v3;
    ll term;
    ll lft;
    if(c==0) {
      cout << "Case #" << tc << ": IMPOSSIBLE\n"; 
      goto place;
    }
    term = n-1;
    loop1(i,1,a-c) {
      v1.push_back(term--);
    }
    reverse(v1.begin(),v1.end());
    term = n-1;
    loop1(i,1,b-c) {
      v2.push_back(term--);
    }
    lft = n - c - v1.size() - v2.size();
    if(lft < 0) {
      cout << "Case #" << tc << ": IMPOSSIBLE\n"; 
      goto place;
    }
    
    loop(i,c) {
      v3.push_back(n);
      if(i==0) {
        loop(i,lft) v3.push_back(1);
      }
      else lft=0;
    }
    if((v1.size()==0 and v2.size()==0 and lft>0)) {
      cout << "Case #" << tc << ": IMPOSSIBLE\n"; 
      goto place;
    }
    if(v2.size()==0) reverse(v3.begin(),v3.end());
    cout << "Case #" << tc << ": ";
    loop(i,v1.size()) cout << v1[i] << " "; 
    loop(i,v3.size()) cout << v3[i] << " "; 
    loop(i,v2.size()) cout << v2[i] << " "; 
    cout << "\n";
    place: ;
  }
}