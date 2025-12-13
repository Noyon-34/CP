#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

ll __lcm(int a, int b) {
	return (a * b) / __gcd(a, b);
}
void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
    	cin >> v[i];
    }

    sort(v.begin(), v.end());
    int mx = v[n - 1];
    int gcd = mx - v[0];

    for(int i = 1; i < n - 1; i++) {
    	int d = mx - v[i];
    	gcd = __gcd(d, gcd);
    }

    ll people = 0;
    for(int i = 0; i < n - 1; i++) {
    	int d = mx - v[i];
    	people += d / gcd;
    }

    cout << people << " " << gcd << '\n';
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