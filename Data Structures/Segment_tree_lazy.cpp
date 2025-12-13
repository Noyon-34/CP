#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;
int a[N];
int t[4 * N];
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

int query(int node, int b, int e, int i, int j) {
	push(node, b, e);
	if(b > j || e < i) {
		return 0;
	}
	if(i <= b && e <= j) {
		return t[node];
	}

	int l = 2 * node, r = 2 * node + 1;
	int mid = (b + e) / 2;

	return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}
void solve() {
    int n = 7;
    for(int i = 1; i <= n; i++)
    	a[i] = i;
    build(1, 1, n);
    cout << query(1, 1, n, 2, 5) << '\n';
    update(1, 1, n, 2, 5, 3);
    cout << query(1, 1, n, 2, 5) << '\n';
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