#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7, mod = 1e9 + 7;
using ll = long long;

int ways[N];
void solve() {
    int n = 100000;
    ways[1] = 1;
    ways[2] = 1;
    ways[3] = 2;

    for(int i = 4; i <= n; i++) {
    	ways[i] = (ways[i - 1] + ways[i - 3]) % mod;
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