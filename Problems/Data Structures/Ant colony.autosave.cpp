#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;

int a[N];
struct node {
  int gcd, count;
};

node t[N * 4];

node merge(node l, node r) {
  node ans;
  ans.gcd = __gcd(l.gcd, r.gcd);
  ans.count = 0;
  if (l.gcd == ans.gcd) {
    ans.count += l.count;
  }
  if (r.gcd == ans.gcd) {
    ans.count += r.count;
  }
  return ans;
}
void build(int n, int b, int e) {
  if (b == e) {
    t[n].gcd = a[b];
    t[n].count = 1;
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  build(l, b, mid);
  build(r, mid + 1, e);
  t[n] = merge(t[l], t[r]);
}

node query(int n, int b, int e, int i, int j) {
  if (e < i or j < b) return {0, 0};
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
    	int l, r; cin >> l >> r;
    	node ans = query(1, 1, n, l, r);
    	cout << (r - l + 1) - ans.count << '\n';
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