#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7, mod = 1e9 + 7;
using ll = long long;

int ways[N];
int count (int n) {
	if(n == 0)
		return 1;
	if(ways[n] != -1)
		return ways[n];

	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += count(n - i);
		ans %= mod;
	}
	return ways[n] = ans;
}

void solve() {
	memset(ways, -1, sizeof ways);
    cout << count(7);
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