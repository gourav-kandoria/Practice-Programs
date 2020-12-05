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
        string s;
        cin >> s;
        stack<char> stk;
        ll i=1;
        for(int i=0; i<s.length(); i++) {
            if(s[i]=='(' or s[i]=='{' or s[i]=='[') {
                stk.push(s[i]);
            }
            else if(s[i]==')') {
                if(!stk.empty() and stk.top()=='(') stk.pop();
                else {
                    cout << "not balanced\n";
                    goto label;
                }
            }
            else if(s[i]==']') {
                if(!stk.empty() and stk.top()=='[') stk.pop();
                else {
                    cout << "not balanced\n";
                    goto label;
                }
            }
            else if(s[i]=='}') {
                if(!stk.empty() and stk.top()=='{') stk.pop();
                else {
                    cout << "not balanced\n";
                    goto label;
                }
            }
        }
        if(!stk.empty()) {
            cout << "not balanced\n";
            goto label;
        }
        cout << "balanced\n";
        label: ;
    }
}