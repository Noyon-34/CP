#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
using ll = long long;

vector<int> v(N);
pair<int, int> t[4 * N];

pair<int, int> combine (pair<int, int> a, pair<int, int> b) {
	if(a.first > b.first)
		return b;
	if(a.first < b.first)
		return a;
	return make_pair(a.first, a.second + b.second);
}

void build (int node, int b, int e) {
	if(b == e) {
		t[node] = make_pair(v[b], 1);
		return;
	}

	int l = 2 * node, r = 2 * node + 1;
	int mid = (b + e) / 2;

	build(l, b, mid);
	build(r, mid + 1, e);

	t[node] = combine(t[l], t[r]);
}

void update(int node, int b, int e, int i, int x) {
	if(b > i || e < i) {
		return;
	}
	if(b == e && b == i) {
		t[node] = make_pair(x, 1);
		return;
	}
	int l = 2 * node, r = 2 * node + 1;
	int mid = (b + e) / 2;

	update(l, b, mid, i, x);
	update(r, mid + 1, e, i, x);

	t[node] = combine(t[l], t[r]);
}

pair<int, int> query (int node, int b, int e, int i, int j) {
	if(b > j || e < i) {
		return make_pair(INT_MAX, 0);
	}
	if(b >= i && e <= j) {
		return t[node];
	}

	int l = 2 * node, r = 2 * node + 1;
	int mid = (b + e) / 2;

	return combine(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}
void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
    	cin >> v[i];
    }

    build(1, 1, n);
    while(m--) {
    	int x; cin >> x;
    	int l, r;
    	cin >> l >> r;
    	if(x == 1) {
    		update(1, 1, n, l + 1, r);
    	} else {
    		pair<int, int> ans = query(1, 1, n, l + 1, r);
    		cout << ans.first << " " << ans.second << '\n';
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