#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7, mod = 1e9 + 7;
using ll = long long;

int ways[N];
int count (int n) {
	if(n == 1)
		return 1;
	if(n == 2)
		return 1;
	if(n == 3)
		return 2;
	if(ways[n] != -1)
		return ways[n];
	return ways[n] = (count(n - 1) + count(n - 3)) % mod;
}

void solve() {
	memset(ways, -1, sizeof ways);
    cout << count(10000);
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