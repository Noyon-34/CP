#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    map<int, int> cnt;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        int d = x;
        for(int j = 2; 1LL * j * j <= x; j++) {
            if(d % j == 0) {
                while(d % j == 0)
                    d /= j;
                cnt[j]++;
            }
        }
        if(d > 1)
            cnt[d]++;
    }

    int ans = 1;
    for(auto it: cnt)
        ans = max(ans, it.second);
    
    cout << ans << '\n';
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