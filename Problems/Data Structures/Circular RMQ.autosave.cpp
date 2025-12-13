#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
using ll = long long;

int a[N];
ll t[4 * N], lazy[4 * N];

void push(int n, int b, int e) {
	if(lazy[n] == 0)
		return;
	t[n] = t[n] + lazy[n];

	if(b != e) {
		int l = 2 * n, r = 2 * n + 1;
		lazy[l] += lazy[n];
		lazy[r] += lazy[n];
	}

	lazy[n] = 0;
}

void build(int n, int b, int e) {
  if (b == e) {
    t[n] = a[b];
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  build(l, b, mid);
  build(r, mid + 1, e);
  t[n] = min(t[l], t[r]);
}

void upd(int n, int b, int e, int i, int j, int v) {
  push(n, b, e);
  if (j < b or e < i) return;
  if (i <= b && e <= j) {
    lazy[n] = v;
    push(n, b, e);
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  upd(l, b, mid, i, j, v);
  upd(r, mid + 1, e, i, j, v);
  t[n] = min(t[l], t[r]);
}

ll query(int n, int b, int e, int i, int j) {
    push(n, b, e);
  if (e < i or j < b) return INT_MAX;
  if (b >= i and e <= j) {
    return t[n];
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  return min(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}

void solve() {
    int n; cin >> n;

    for(int i = 1; i <= n; i++)
    	cin >> a[i];
    build(1, 1, n);
    int q; cin >> q;
    cin.ignore();
    while(q--) {
    	string s;
    	getline(cin, s);
    	stringstream in(s);
    	int l, r, v;
    	in >> l >> r;

    	if(in >> v) {
    		if(l <= r) {
    			upd(1, 1, n, l + 1, r + 1, v);
    		}
    		else {
    			upd(1, 1, n, l + 1, n, v);
    			upd(1, 1, n, 1, r + 1, v);
    		}
    	}
    	else {
    		if(l <= r) {
    			cout << query(1, 1, n, l + 1, r + 1) << '\n';
    		}
    		else {
    			ll x = query(1, 1, n, l + 1, n);
    			ll y = query(1, 1, n, 1, r + 1);
    			cout << min(x, y) << '\n';
    		}
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