#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;

struct node {
  int occur[3];
};

node t[4 * N];
int lazy[4 * N];

void push (int n, int b, int e) {
	if(lazy[n] == 0)
		return;

    node cur = t[n];
    for(int i = 0; i < 3; i++) {
      t[n].occur[(i + lazy[n]) % 3] = cur.occur[i];
    }
		
	if(b != e) {
  	int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
		lazy[l] = (lazy[l] + lazy[n]) % 3;
		lazy[r] = (lazy[r] + lazy[n]) % 3;
	}

	lazy[n] = 0;
}

node merge(node l, node r) {
  node ans;
  for(int i = 0; i < 3; i++) {
    ans.occur[i] = l.occur[i] + r.occur[i];
  }
  return ans;
}

void build(int n, int b, int e) {
	lazy[n] = 0;
  if (b == e) {
    t[n].occur[0] = 1, t[n].occur[1] = t[n].occur[2] = 0;
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  build(l, b, mid);
  build(r, mid + 1, e);
  t[n] = merge(t[l], t[r]);
}

void upd(int n, int b, int e, int i, int j) {
	push(n, b, e);
  if (j < b or e < i) return;
  if (b >= i and e <= j) {
    lazy[n] = 1;
    push(n, b, e);
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  upd(l, b, mid, i, j);
  upd(r, mid + 1, e, i, j);
      t[n] = merge(t[l], t[r]);
}

int query(int n, int b, int e, int i, int j) {
	push(n, b, e);
  if (e < i or j < b) return 0;
  if (b >= i and e <= j) {
    return t[n].occur[0];
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}

void solve(int cs) {
    int n, q; cin >> n >> q;
    cout << "Case " << cs << ":\n";
    build(1, 1, n);
    while(q--) {
    	int ty, l, r; cin >> ty >> l >> r;
    	if(!ty) {
    		upd(1, 1, n, l + 1, r + 1);
    	}
    	else {
    	 cout << query(1, 1, n, l + 1, r + 1) << '\n';
    	}
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1, cs = 0;
    cin >> t;
    while(t--) {
        solve(++cs);
    }
    return 0;
}