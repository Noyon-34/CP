#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
        
    vector<int> prefix_sum(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + v[i - 1];
    }

    map<int, int> mp;
    for(int i = 0; i <= n; i++) {
        int mod = (prefix_sum[i] % k + k) % k;
        mp[mod]++;
    }

    long long ans = 0;
    for(auto it: mp) {
        int n = it.second - 1;
        ans += (n * (n + 1)) / 2;
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