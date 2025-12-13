#include<bits/stdc++.h>
using namespace std;

const int N = 3e4 + 7;
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
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    }

    int q; cin >> q;
    vector<pair<int, int>> vp[q + 1];
    for(int i = 1; i <= q; i++) {
    	int l, r;
    	cin >> l >> r;
        vp[r].push_back({l, i});
    }
    build(1, 1, n);

    map<int, int> l_o;
    vector<int> ans(q + 1);
    for(int i = 1; i <= n; i++) {
        if(l_o.find(a[i]) != l_o.end()) {
            upd(1, 1, n, l_o[a[i]], -1);
        }
        l_o[a[i]] = i;
        upd(1, 1, n, i, 1);

        for(auto [l, q_id]: vp[i]) {
            ans[q_id] = query(1, 1, n, l, i);
        }
    }
    
    for(int i = 1; i <= q; i++) {
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