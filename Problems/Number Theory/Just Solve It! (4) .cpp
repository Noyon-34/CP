#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;
#define new cout << '\n';
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve() {
    ll n, m, l, r;
    cin >> n >> m >> l >> r;
    
    ll gcd = __gcd(n, m);
    ll lcm = (n * m) / gcd;

    ll ans = r / lcm - (l - 1) / lcm;

    cout << ans << '\n';
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