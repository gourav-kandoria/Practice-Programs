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
        ll n,s; cin >> n >> s;
        ll arr[n];
        loop(n) cin >> arr[i];
        ll sum = arr[0];
        ll b = 0; ll e = 0;
        for(ll i=1; i<n; i++) {
            e++;
            sum = sum+arr[i];
            while(sum>s and b<e) {
                sum = sum - arr[b];
                b++;
            } 
            if(sum==s) {
                cout << b+1 << " " << e+1 << "\n";
                goto label1;
            }
        }
        cout << -1 << "\n";
        label1: ;
    }
}