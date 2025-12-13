#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;
#define new cout << '\n';
#define yes cout << "Yes\n";
#define no cout << "No\n";

void solve() {
    ll a, b;
    cin >> a >> b;

    while(1) {
        ll gcd = __gcd(a, b);
        if(gcd == 1)
            break;
        b /= gcd;
    }

    if(b == 1)
        yes
    else
        no
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}