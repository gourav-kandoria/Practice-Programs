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
        ll arr[n+1];
        arr[0] = 0;
        loop1(1,n) {
            cin >> arr[i];
            arr[i]+=arr[i-1];
        }
        for(int i=1; i<=n; i++) {
            ll ele = arr[i] - s;
            ll* ptr = lower_bound(arr,arr+n,ele);
            if(*ptr == ele) {
                cout << (ptr-arr)+1<< " " << i << "\n";
                goto label1;
            }
        }
        cout << "-1\n";
        label1: ;
    }
}