#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
using ll = long long;

int a[N];
ll t[4 * N];
int lazy[4 * N];

void build(int node, int b, int e) {
	lazy[node] = 0;
	if(b == e) {
		t[node] = a[b];
		return;
	}
	int l = 2 * node, r = 2 * node + 1;
	int mid = (b + e) / 2;

	build(l, b, mid);
	build(r, mid + 1, e);

	t[node] = t[l] + t[r];
}

void push(int node, int b, int e) {
	if(lazy[node] == 0)
		return;
	t[node] += lazy[node] * (e - b + 1);

	int l = 2 * node, r = 2 * node + 1;
	int mid = (b + e) / 2;

	if(b != e) {
		lazy[l] += lazy[node];
		lazy[r] += lazy[node];
	}
	lazy[node] = 0;
}
void update(int node, int b, int e, int i, int j, int v) {
	push(node, b, e);
	if(b > j || e < i) {
		return;
	}
	if(i <= b && e <= j) {
		lazy[node] = v;
		push(node, b, e);
		return;
	}
	int l = 2 * node, r = 2 * node + 1;
	int mid = (b + e) / 2;

	update(l, b, mid, i, j, v);
	update(r, mid + 1, e, i, j, v);

	t[node] = t[l] + t[r];
}

ll query(int node, int b, int e, int i) {
	push(node, b, e);
	if(b > i || e < i) {
		return 0;
	}
	if(i <= b && e <= i) {
		return t[node];
	}

	int l = 2 * node, r = 2 * node + 1;
	int mid = (b + e) / 2;

	return query(l, b, mid, i) + query(r, mid + 1, e, i);
}
void solve() {
    int n, m;
    cin >> n >> m;

    while(m--) {
    	int x;
    	cin >> x;

    	if(x == 1) {
    		int l, r, v;
    		cin >> l >> r >> v;
    		update(1, 1, n, l + 1, r, v);
    	}
    	else {
    		int l;
    		cin >> l;
    		cout << query(1, 1, n, l + 1) << '\n';
    	}
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