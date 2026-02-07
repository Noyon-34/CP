#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;

int step[N];
int min_step (int n) {
	if(n == 1)
		return 0;
	if(step[n] != -1)
		return step[n];
	int ans = min_step(n - 1) + 1;
	if(n % 2 == 0) {
		ans = min(ans, min_step(n / 2) + 1);
	}
	if(n % 3 == 0) {
		ans = min(ans, min_step(n / 3) + 1);
	}
	step[n] = ans;
	return step[n];
}
void solve() {
	memset(step, -1, sizeof step);
    int n = 1;
    cout << min_step(n);
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