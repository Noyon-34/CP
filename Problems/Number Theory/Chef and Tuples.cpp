#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;
#define new cout << '\n';
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> v;
    for(int i = 1; 1LL * i * i <= n; i++) {
        if(n % i == 0) {
            v.push_back(i);
            if(i != n / i)
                v.push_back(n / i);
        }
    }

    sort(v.begin(), v.end());
    ll ans = 0;

    for(auto it1: v) {
        if(it1 <= a) {
            for(auto it2: v) {
                if(it2 <= b) {
                    if ((n / (1LL * it1 * it2)) <= c && (n % (1LL * it1 * it2)) == 0)
                        ans++;
                }
            }
        }
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