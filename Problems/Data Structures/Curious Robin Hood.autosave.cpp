#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;

vector<int> v;
int t[4 * N];

void build (int node, int b, int e) {
	if(b == e) {
		t[node] = v[b];
		return;
	}

	int l = 2 * node, r = 2 * node + 1;
	int mid = (b + e) / 2;

	build(l, b, mid);
	build(r, mid + 1, e);

	t[node] = t[l] + t[r];
}

void update(int node, int b, int e, int i, int x) {
	if(b > i || e < i) {
		return;
	}

	if(b == e && b == i) {
		t[node] += x;
		return;
	}

	int l = 2 * node, r = 2 * node + 1;
	int mid = (b + e) / 2;

	update(l, b, mid, i, x);
	update(r, mid + 1, e, i, x);

	t[node] = t[l] + t[r];
}

int query (int node, int b, int e, int i, int j) {
	if(b > j || e < i) {
		return 0;
	}

	if(i <= b && e <= j) {
		return t[node];
	}

	int l = 2 * node, r = 2 * node + 1;
	int mid = (b + e) / 2;


	return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}

void solve(int cs) {
    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++) {
    	int it; cin >> it;
    	v.push_back(it);
    }

    cout << "Case " << cs << ": \n";

    build(1, 1, n);
    while(q--) {
    	int t;
    	cin >> t;

    	if(t == 1) {
    		int i; cin >> i;
    		int v = query(1, 1, n, i + 1, i + 1);
    		cout << v << '\n';
    		update(1, 1, n, i + 1, -v);
    	}
    	else {
    		int i, j; cin >> i >> j;
    		if(t == 2) {
    			update(1, 1, n, i + 1, j);
    		} else {
    			cout << query(1, 1, n, i + 1, j + 1) << '\n';
    		}
    	}
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	v.push_back(0);

    int t = 1, cs = 0;
    cin >> t;
    while(t--) {
        solve(++cs);
    }
    return 0;
}