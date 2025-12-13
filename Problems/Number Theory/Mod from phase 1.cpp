#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;
#define new cout << '\n';
#define yes cout << "YES\n";
#define no cout << "NO\n";

ll mul(ll a, ll b, ll p) {
    return (ll)((__int128)a * b % p);
}

ll power(ll a, ll b, ll p) {
    ll ans = 1 % p;
    while(b) {
        if (b & 1)
            ans = mul(ans, a, p);
        a = mul(a, a, p);
        b >>= 1;
    }
    return ans;
}

ll inverse(ll a, ll p) {
    return power(a, p - 2, p);
}

void solve() {
    ll a, b, p;
    cin >> a >> b >> p;

    cout << power(a, b, p) << '\n';
    cout << mul(a, b, p) << '\n';
    cout << mul(a, inverse(b, p), p) << '\n';
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