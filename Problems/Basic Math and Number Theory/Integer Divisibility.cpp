#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

void solve(int cs) {
    int n, d;
    cin >> n >> d;

    ll num = 0, ans = 0;
    while(1) {
        num = (num * 10 + d) % n;
        ans++;
        if(!num)
            break;
    }

    cout << "Case " << cs << ": " << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1, cs = 0;
    cin >> t;
    while(t--) {
        solve(++cs);
    }
    return 0;
}