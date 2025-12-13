#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

void solve(int cs) {
    ll w;
    cin >> w;

    cout << "Case " << cs << ": ";
    if((w & 1)) {
        cout << "Impossible\n";
        return;
    }

    ll m = 1;
    while(w % 2 == 0) {
        m *= 2;
        w /= 2;
    }

    cout << w << " " << m << '\n';
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