#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MAX = 1e10;
const int N = 1e5 + 9;

vector<ll> v[N];
void divs() {
    int spf[N];
    for(int i = 2; i < N; i++)
        spf[i] = i;
    
    for(int i = 1; i < N; i++) {
        if(spf[i] == i) {
            for(int j = i; j < N; j += i) {
                spf[j] = min(spf[j], i);
            }
        }
    }

    for(int i = 1; 1LL * i * i <= MAX; i++) {
        int x = i;
        int divisors = 1;
        while(x > 1) {
            int p = spf[x], exp = 0;
            while(x % p == 0) {
                exp++;
                x /= p;
            }
            divisors *= (2 * exp + 1);
        }
        v[divisors].push_back(1LL * i * i);
    }
}
void solve() {
    int k; ll l, h;
    cin >> k >> l >> h;

    int ans = 0;
    ans = upper_bound(v[k].begin(), v[k].end(), h) - lower_bound(v[k].begin(), v[k].end(), l);

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    divs();
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}