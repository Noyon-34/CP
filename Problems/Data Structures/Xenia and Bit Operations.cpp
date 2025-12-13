#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
using ll = long long;

int v[N];
int t[4 * N];

void build (int node, int b, int e, bool orr) {
	if(b == e) {
		t[node] = v[b];
		return;
	}

	int l = 2 * node, r = 2 * node + 1;
	int mid = (b + e) / 2;

	build(l, b, mid, !orr);
	build(r, mid + 1, e, !orr);

	if(orr)
		t[node] = t[l] | t[r];
	else
		t[node] = t[l] ^ t[r];
}

void update (int node, int b, int e, int i, int x, bool orr) {
	if(b > i || e < i) 
		return;
	if(b == e) {
		t[node] = x;
		return;
	}

	int l = 2 * node, r = 2 * node + 1;
	int mid = (b + e) / 2;

	update(l, b, mid, i, x, !orr);
	update(r, mid + 1, e, i, x, !orr);

	if(orr)
		t[node] = t[l] | t[r];
	else
		t[node] = t[l] ^ t[r];
}

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= (1 << n); i++)
    	cin >> v[i];

    build(1, 1, (1 << n), n & 1);
    while(m--) {
    	int i, x;
    	cin >> i >> x;

    	update(1, 1, (1 << n), i, x, n & 1);
    	cout << t[1] << '\n';
    }
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