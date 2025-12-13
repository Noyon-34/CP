#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;
#define new cout << '\n';
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve() {
    string a;
    int b;

    //If a is divisible by b. a is a large number
    cin >> a >> b;
    int ans = 0;
    for(int i = 0; i < a.size(); i++) {
        ans = (ans * 10 + (a[i] - '0')) % b;
    }

    if (!ans) {
        cout << "a is divisible by b";
    } else {
        cout << "a is not divisible by b ans remainder is " << ans;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}