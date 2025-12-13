#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    int x = n, ans = 0;
    for(int i = 2; 1LL * i * i <= n; i++) {
        int exp = 0;
        while(x % i == 0) {
            exp++;
            x /= i;
        }
        ans = max(ans, exp);
    }
    if(x > 1)
        ans = max(ans, 1);

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