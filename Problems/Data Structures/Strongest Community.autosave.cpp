#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;

int a[N];
struct per_node {
	int first_element, first_element_occ;
	int last_element, last_element_occ;
	int strongest_com;
};

per_node t[4 * N];

per_node merge (per_node l, per_node r) {
	if(l.first_element == -1) {
		return r;
	}
	if(r.first_element == -1) {
		return l;
	}

	per_node ans;
	ans.first_element = l.first_element;
	ans.first_element_occ = l.first_element_occ;
	if(l.first_element == r.first_element) {
		ans.first_element_occ += r.first_element_occ;
	}

	ans.last_element = r.last_element;
	ans.last_element_occ = r.last_element_occ;
	if(r.last_element == l.last_element) {
		ans.last_element_occ += l.last_element_occ;
	}

	ans.strongest_com = max(l.strongest_com, r.strongest_com);

	if(l.last_element == r.first_element) {
		ans.strongest_com = max(ans.strongest_com, l.last_element_occ + r.first_element_occ);
	}

	return ans;
}

void build (int node, int b, int e) {
	if(b == e) {
		t[node].first_element = t[node].last_element = a[b];
		t[node].first_element_occ = t[node].last_element_occ = 1;
		t[node].strongest_com = 1;
		return;
	}

	int l = 2 * node, r = 2 * node + 1;
	int mid = (b + e) / 2;

	build(l, b, mid);
	build(r, mid + 1, e);

	t[node] = merge(t[l], t[r]);
}

per_node query (int node, int b, int e, int i, int j) {
	if(b > j || e < i) {
		return {-1, -1, -1, -1, -1};
	}

	if(i <= b && e <= j) {
		return t[node];
	}

	int l = 2 * node, r = 2 * node + 1;
	int mid = (b + e) / 2;


	return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}

void solve(int cs) {
    int n, c, q;
    cin >> n >> c >> q;

    for (int i = 1; i <= n; i++)
    	cin >> a[i];

    build(1, 1, n);
    cout << "Case " << cs << ":\n";
    while (q--) {
    	int l, r;
    	cin >> l >> r;
    	per_node ans = query (1, 1, n, l, r);
    	cout << ans.strongest_com << '\n';
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