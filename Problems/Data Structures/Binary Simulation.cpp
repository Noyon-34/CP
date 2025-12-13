#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;

int tree[4 * N];

void build (int node, int b, int e) {
    if(b == e) {
        tree[node] = 0;
        return;
    }

    int l = 2 * node, r = 2 * node + 1;
    int mid = (b + e) / 2;

    build(l, b, mid);
    build(r, mid + 1, e);

    tree[node] = tree[l] + tree[r];
}

void update(int node, int b, int e, int i, int x) {
    if(b > i || e < i) {
        return;
    }

    if(b == e && b == i) {
        tree[node] += x;
        return;
    }

    int l = 2 * node, r = 2 * node + 1;
    int mid = (b + e) / 2;

    update(l, b, mid, i, x);
    update(r, mid + 1, e, i, x);

    tree[node] = tree[l] + tree[r];
}

int query (int node, int b, int e, int i, int j) {
    if(b > j || e < i) {
        return 0;
    }

    if(i <= b && e <= j) {
        return tree[node];
    }

    int l = 2 * node, r = 2 * node + 1;
    int mid = (b + e) / 2;


    return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}

void solve(int cs) {
    string s; cin >> s;
    int q; cin >> q;

    int n = s.size();
    
    build(1, 1, n);
    cout << "Case " << cs << ":\n";

    while(q--) {
    	char ch; cin >> ch;
    	if(ch == 'I') {
    		int l, r;
    		cin >> l >> r;
    		update(1, 1, n, l, 1);
    		if(r + 1 <= n)
    			update(1, 1, n, r + 1, -1);
    	}
    	else {
    		int i;
    		cin >> i;
    		int cn = query(1, 1, n, 1, i);
    		if(cn & 1)
    			cout << !(s[i - 1] - '0') << '\n';
    		else
    			cout << s[i - 1] - '0' << '\n';		
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