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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll arr[n];
        for(ll i=0; i<n; i++) {
            cin >> arr[i];
        }
        ll sol[n];
        sol[0] = arr[0];
        ll res = sol[0];
        for(ll i=1; i<n; i++) {
            sol[i] = max(arr[i]+sol[i-1],arr[i]);
            res = max(res,sol[i]);
        }
        cout << res << endl;
    }
}