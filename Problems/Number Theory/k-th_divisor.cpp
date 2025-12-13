#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;
#define new cout << '\n';
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> v;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            v.push_back(i);
            if(i != n / i)
                v.push_back(n / i);
        }
    }

    sort(v.begin(), v.end());
    if(v.size() < k)
        cout << -1;
    else
        cout << v[k-1];
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