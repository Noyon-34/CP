#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;
#define new cout << '\n';
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve() {
    ll l, r;
    cin >> l >> r;

    yes
    for(ll i = l; i <= r; i += 2)
        cout << i << " " << i + 1 << '\n';
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