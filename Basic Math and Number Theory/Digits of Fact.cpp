#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    double ans = 0;
    // for(int i = 1; i <= n; i++) {
    //     ans += log10(i);
    // }
    // O(n)

    ans = ((n * log10(n / M_E) + log10(2 * M_PI * n) / 2.0));
    //O(1)

    cout << floor(ans) + 1 << '\n';
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