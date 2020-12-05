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

string str;
ll level;

pair<vector<ll>, vector<ll> > go_down(ll l, ll r) {
  if(l==r) {
    vector<ll> res(26);
    vector<ll> cnt(26);
    loop(i,26) {
      char ch = str[l];
      if(i!=(ch-'a')) {
        res[i]=1; cnt[i] = 0;
      }
      else {
        res[i] = 0; cnt[i] = 1;
      }
    }
    level = 25;
    return {res, cnt};
  }
  else {
    vector<ll> res(26);
    ll sz = (r-l+1)/2;
    auto out1 = go_down(l, (l+r)/2);
    auto out2 = go_down((l+r)/2+1, r);
    vector<ll> res1 = out1.first; vector<ll> res2 = out2.first;
    vector<ll> cnt1 = out1.second; vector<ll> cnt2 = out2.second;
    loop(i,level) {
      res[i] = min(sz-cnt1[i]+res2[i+1], res1[i+1]+sz-cnt2[i]);
    } 
    vector<ll> cnt(26);
    loop(i,26) cnt[i]=cnt1[i]+cnt2[i];
    level--;
    return {res,cnt};
  }
}

int main() {
  fast_io
  ll t=1; 
  cin >> t;
  while(t--) {
    ll temp; cin >> temp;
    cin >> str;
    cout << go_down(0,str.length()-1).first[0] << "\n";
  }
}