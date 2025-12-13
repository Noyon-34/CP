#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

ll ans(ll n, ll a, ll b, ll p, ll q) {
    return ((n / a) - (n / ((a * b) / (__gcd(a , b))))) * p + (n / b) * q;
}
void solve() {
    ll n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;

    if(p < q)
        cout << ans(n, a, b, p, q);
    else
        cout << ans(n, b, a, q, p);
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