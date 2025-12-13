#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;
int a[N];
int t[4 * N];

void build(int node, int b, int e) {
	if(b == e) {
		t[node] = b;
		return;
	}
	int l = 2 * node, r = 2 * node + 1;
	int mid = (b + e) / 2;
	build(l, b, mid);
	build(r, mid + 1, e);
	t[node] = t[l] + t[r];
}

int query(int node, int b, int e, int i, int j) {
	if(b > j || e < i) {
		return 0;
	}
	if(b >= i && e <= j) {
		return t[node];
	}

	int l = 2 * node, r = 2 * node + 1;
	int mid = (b + e) / 2;
	return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}

void update(int node, int b, int e, int i, int x) {
	if(b > i || e < i) {
		return;
	}
	if(b == i && b == e) {
		t[node] = x;
		return;
	}

	int l = 2 * node, r = 2 * node + 1;
	int mid = (b + e) / 2;

	update(l, b, mid, i, x);
	update(r, mid + 1, e, i, x);

	t[node] = t[l] + t[r];
}
void solve() {
    int n = 5;
    for(int i = 1; i <= n; i++)
    	a[i] = i;
    build(1, 1, n);
    cout << query(1, 1, n, 2, 4) << '\n';
    update(1, 1, n, 3, 7);
    cout << query(1, 1, n, 2, 4) << '\n';
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