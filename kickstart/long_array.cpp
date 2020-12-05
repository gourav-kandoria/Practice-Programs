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
  fast_io;
  ll t=1; 
  cin >> t;
  loop1(tc,1,t) {
    ll n; cin >> n;
    ll arr[n];
    cin >> arr[0];
    ll prev; ll len=1;
    ll ans=2;
    loop1(i,1,n-1) {
      cin >> arr[i];
      ll di = arr[i]-arr[i-1];
      if(i==1) {
        prev = di; 
        len = 1;
      }
      else if(di==prev) {
        len++;
      }
      else {
        prev = di;
        len = 1;
      }
      ans = max(ans,len+1);
    }
    cout << "Case #" << tc << ": " << ans << "\n";
  }
}