#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7, B = 30;
using ll = long long;

int t[4 * N], f[N], l[N], r[N], required_AND[N], ans[N];

const int inf = 1e9 + 9;

struct node {
  int mn, count;
};

node t[N * 4];

node merge(node l, node r) {
  node ans;
  ans.mn = min(l.mn, r.mn);
  ans.count = 0;
  if (l.mn == ans.mn) {
    ans.count += l.count;
  }
  if (r.mn == ans.mn) {
    ans.count += r.count;
  }
  return ans;
}
void build(int n, int b, int e) {
  if (b == e) {
    t[n].mn = a[b];
    t[n].count = 1;
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  build(l, b, mid);
  build(r, mid + 1, e);
  t[n] = merge(t[l], t[r]);
}

void upd(int n, int b, int e, int i, int v) {
  if (i < b or e < i) return;
  if (b == e) {
    t[n].mn = v;
    t[n].count = 1;
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  upd(l, b, mid, i, v);
  upd(r, mid + 1, e, i, v);
  t[n] = merge(t[l], t[r]);
}

node query(int n, int b, int e, int i, int j) {
  if (e < i or j < b) return {inf, 1};
  if (b >= i and e <= j) {
    return t[n];
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}

void build(int n, int b, int e) {
  if (b == e) {
    t[n] = ans[b];
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  build(l, b, mid);
  build(r, mid + 1, e);
  t[n] = (t[l] & t[r]);
}

int query(int n, int b, int e, int i, int j) {
  if (e < i or j < b) return (1 << 30) - 1;
  if (b >= i and e <= j) {
    return t[n];
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  return (query(l, b, mid, i, j) & query(r, mid + 1, e, i, j));
}
void solve() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i] >> required_AND[i];
    }

    for(int k = 0; k < B; k++) {
        for(int i = 1; i <= n; i++) {
            f[i] = 0;
        }
        for(int i = 1; i <= m; i++) {
            if((required_AND[i] >> k) & 1) {
                f[l[i]]++;
                f[r[i] + 1]--;
            }
        }

        for(int i = 1; i <= n; i++) {
            f[i] += f[i - 1];
        }

        for(int i = 1; i <= n; i++) {
            if(f[i]) {
                ans[i] |= (1 << k);
            }
        }
    }

    build(1, 1, n);

    for(int i = 1; i <= m; i++) {
        int curr = query(1, 1, n, l[i], r[i]);
        if(curr != required_AND[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
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