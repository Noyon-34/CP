#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;
int t[4 * N];

void update(int node, int b, int e, int i) {
	if(b == e) {
		t[node]++;
		return;
	}

	int l = 2 * node, r = 2 * node + 1;
	int mid = (b + e) / 2;

	if(mid >= i)
		update(l, b, mid, i);
	else 
		update(r, mid + 1, e, i);

	t[node] = t[l] + t[r];
}

int query(int node, int b, int e, int i, int j) {
	if(b > j || e < i)
		return 0;
	if(i <= b && e <= j)
		return t[node];

	int l = 2 * node, r = 2 * node + 1;
	int mid = (b + e) / 2;

	return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}
void solve() {
    int n;
    cin >> n;

    vector<int> v(n + 1);
    for(int i = 0; i < n; i++) {
    	int x; cin >> x;
    	v[i] = query(1, 1, n, x + 1, n);
    	update(1, 1, n, x);
    }

    for(int i = 0; i < n; i++)
    	cout << v[i] << " ";
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