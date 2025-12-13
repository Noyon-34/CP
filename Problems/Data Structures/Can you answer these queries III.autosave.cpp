#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7, inf = 1e9 + 7;
using ll = long long;

int a[N];

struct node {
    int mx_p_s, mx_s_s;
    int mx_sub_s, total_s;
};
node t[4 * N];

node merge(node l, node r) {
    if(l.total_s == inf)
        return r;
    if(r.total_s == inf)
        return l;
    node ans;
    ans.mx_sub_s = max(r.mx_sub_s, l.mx_sub_s);
    ans.mx_sub_s = max(ans.mx_sub_s, l.mx_s_s + r.mx_s_s);
    ans.mx_p_s = max(l.mx_p_s, l.total_s + r.mx_p_s);
    ans.mx_s_s = max(r.mx_s_s, r.total_s + l.mx_s_s);

    ans.total_s = l.total_s + r.total_s;
    return ans;
}
void build(int n, int b, int e) {
  if (b == e) {
    t[n].mx_p_s = a[b];
    t[n].mx_s_s = a[b];
    t[n].mx_sub_s = a[b];
    t[n].total_s = a[b];
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  build(l, b, mid);
  build(r, mid + 1, e);
  t[n] = merge(t[l], t[r]);
}

void upd(int n, int b, int e, int i, int v) {
  // push(n, b, e);
  if (i < b or e < i) return;
  if (b == e) {
    t[n].mx_p_s = v;
    t[n].mx_s_s = v;
    t[n].mx_sub_s = v;
    t[n].total_s = v;
    // push(n, b, e);
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  upd(l, b, mid, i, v);
  upd(r, mid + 1, e, i, v);
  t[n] = merge(t[l], t[r]);
}

node query(int n, int b, int e, int i, int j) {
    // push(n, b, e);
  if (e < i or j < b) return {inf, inf, inf, inf};
  if (b >= i and e <= j) {
    return t[n];
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}
void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
    	cin >> a[i];

    build(1, 1, n);
    int q; cin >> q;
    while(q--) {
    	int ty; cin >> ty;

    	if(ty) {
    		int l, r; cin >> l >> r;
            node ans = query(1, 1, n, l, r);
    		cout << ans.mx_sub_s << '\n';
    	}
    	else {
    		int i, v; cin >> i >> v;
    		upd(1, 1, n, i, v);
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