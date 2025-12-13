
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
