#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7, mod = 1e9 + 7;
using ll = long long;

int ways[N];
void solve() {
    int n = 10;
    ways[0] = 1;

    for(int i = 1; i <= n; i++) {
        int ans = 0;
        for(int j = 1; j <= i; j++) {
            ans += (ways[i - j]) % mod;
            ways[i] = ans;
        }
    }
    cout << ways[n];
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}