#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

void solve() {
    int d, n, x;
    cin >> d >> n;

    vector<ll> pre(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> x;
        pre[i] = pre[i - 1] + x;
    }

    map<int, int> mp;
    ll ans = 0;
    for(int i = 0; i < n + 1; i++) {
        ans += mp[pre[i] % d];
        mp[pre[i] % d]++;
    }

    cout << ans << '\n';
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