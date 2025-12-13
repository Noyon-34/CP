#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
using ll = long long;

int t[N * 4];

void build(int n, int b, int e) {
  if (b == e) {
    t[n] = 0;
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  build(l, b, mid);
  build(r, mid + 1, e);
  t[n] = t[l] + t[r];
}

void upd(int n, int b, int e, int i, int v) {
  if (i < b or e < i) return;
  if (b == e) {
    t[n] += v;
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  upd(l, b, mid, i, v);
  upd(r, mid + 1, e, i, v);
      t[n] = t[l] + t[r];
}

int query(int n, int b, int e, int i, int j) {
  if (e < i or j < b) return 0;
  if (b >= i and e <= j) {
    return t[n];
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(N);
    for(int i = 1; i <= n; i++) {
    	int x; cin >> x;
        a[x] = i;
    }

    vector<int> p[N];
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j += i) {
            int l = min(a[i], a[j]);
            int r = max(a[i], a[j]);
            p[r].push_back(l);
        }
    }
    vector<pair<int, int>> vp[N];
    for(int i = 1; i <= m; i++) {
    	int l, r; cin >> l >> r;
    	vp[r].push_back({l, i});
    }

    build(1, 1, n);
    vector<ll> ans(m + 1);
    for(int i = 1; i <= n; i++) {
        for(auto it: p[i]) {
            upd(1, 1, n, it, 1);
        }

        for(auto [l, id]: vp[i]) {
            ans[id] = query(1, 1, n, l, i);
        }
    }

    for(int i = 1; i <= m; i++) {
        cout << ans[i] << '\n';
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