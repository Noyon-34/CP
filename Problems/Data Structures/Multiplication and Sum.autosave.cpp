#include<bits/stdc++.h>
using namespace std;

const int N = 100007, mod = 1e9 + 7;
using ll = long long;

ll t[N * 4], lazy[4 * N];

void push (int n, int b, int e) {
	if(lazy[n] == 1)
		return;
	t[n] = 1LL * t[n] * lazy[n] % mod;

	if(b != e) {
  		int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
		lazy[l] = 1LL * lazy[l] * lazy[n] % mod;
		lazy[r] = 1LL * lazy[r] * lazy[n] % mod;
	}

	lazy[n] = 1;
}
void build(int n, int b, int e) {
	lazy[n] = 1;
  if (b == e) {
    t[n] = 1;
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  build(l, b, mid);
  build(r, mid + 1, e);
  t[n] = t[l] + t[r];
}

void upd(int n, int b, int e, int i, int j, int v) {
	push(n, b, e);
  if (j < b or e < i) return;
  if (b >= i and e <= j) {
    lazy[n] = 1LL * lazy[n] * v % mod;
    push(n, b, e);
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  upd(l, b, mid, i, j, v);
  upd(r, mid + 1, e, i, j, v);
      t[n] = (t[l] + t[r]) % mod;
}

ll query(int n, int b, int e, int i, int j) {
	push(n, b, e);
  if (e < i or j < b) return 0;
  if (b >= i and e <= j) {
    return t[n];
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  return (query(l, b, mid, i, j) + query(r, mid + 1, e, i, j)) % mod;
}

void solve() {
    int n, m;
    cin >> n >> m;

    build(1, 1, n);
    while (m--) {
    	int ty; cin >> ty;
    	if(ty == 1) {
    		int l, r, v; cin >> l >> r >> v;
    		upd(1, 1, n, l + 1, r, v);
    	}
    	else {
    		int l, r; cin >> l >> r;
    		cout << query(1, 1, n, l + 1, r) << '\n';
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