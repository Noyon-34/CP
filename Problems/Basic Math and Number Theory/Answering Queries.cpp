#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

void solve(int cs) {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += 1LL * a[i] * (n - 2 * i - 1);
    }

    cout << "Case " << cs << ": \n";
    while(q--) {
        int t;
        cin >> t;

        if(t) {
            cout << sum << '\n';
        }
        else {
            int x, v;
            cin >> x >> v;
            sum -= 1LL * a[x] * (n - 2 * x - 1);
            sum += 1LL * v * (n - 2 * x - 1);
        }
    }
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