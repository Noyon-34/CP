#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

void solve() {
    ll x;
    cin >> x;

    ll ans;
    for(ll i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            if(__gcd(i, x / i) == 1)
                ans = i;
        }
    }
    cout << ans << " " << x / ans << '\n';
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