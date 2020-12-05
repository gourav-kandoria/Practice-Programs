#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
ll mod = 1000000007;
#define loop(i,n) for(ll i=0; i<n; i++)
#define loop1(i,a,b) for(ll i=a; i<=b; i++)
#define rloop(i,n) for(ll i=n-1; i>=0; i--)
#define rloop1(i,a,b) for(ll i=a; i>=b; i--)
// template <typename T>
// void print(T a, T b, string end="\n") {
//     for_each(a,b,[](auto & i){cout << i << " ";});
//     cout << end;
// }


void solution1() {
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        pair<ll,ll> vec[n];
        loop(i,n) {
            cin >> vec[i].first;
            vec[i].second = i;
        }
        sort(vec,vec+n,[](pair<ll,ll> a, pair<ll,ll> b) {
           if(a.first==b.first) {
               return a.second < b.second;
           }
           else return a.first < b.first;
        });
        ll mx = 0;
        ll mn = vec[0].second;
        for(ll i=1; i<n; i++) {
            mx = max(mx, vec[i].second-mn);
            mn = min(vec[i].second,mn);
        }
        cout << mx << "\n";
    }
}

void solution2() {
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll* arr = new ll[n];
        loop(i,n) cin >> arr[i];
        ll* lmin = new ll[n]; 
        ll* rmax = new ll[n];
        lmin[0] = arr[0];
        rmax[n-1] = arr[n-1];

        loop1(i,1,n-1) {
            lmin[i]=(arr[i]<lmin[i-1]?arr[i]:lmin[i-1]);
        }
        
        rloop1(i,n-2,0) {
            rmax[i]=(arr[i]>rmax[i+1]?arr[i]:rmax[i+1]);
        }

        ll mx = 0; ll b=0;

        loop(i,n) {
            loop1(j,b,n-1) {
                if(rmax[j]<lmin[i]) break;
                b = j;
            }
            mx = max(mx, b-i);
        }
        cout << mx << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //solution1();
    solution2();
}