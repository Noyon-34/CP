#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7, B = 20;
using ll = long long;

int a[N];

struct node {
    int on[B], off[B];
};
node t[4 * N];
int lazy[4 * N];

void push(int n, int b, int e) {
    if(lazy[n] == 0)
        return;
    
    for(int i = 0; i < B; i++) {
        if((lazy[n] >> i) & 1)
            swap(t[n].on[i], t[n].off[i]);
    }

    if(b != e) {
        int l = 2 * n, r = 2 * n + 1;
        lazy[l] ^= lazy[n];
        lazy[r] ^= lazy[n];
    }

    lazy[n] = 0;
}
node merge(node l, node r) {
    node ans;
    for(int i = 0; i < B; i++) {
        ans.on[i] = l.on[i] + r.on[i];
        ans.off[i] = l.off[i] + r.off[i];
    }
    return ans;
}
void build (int n, int b, int e) {
    lazy[n] = 0;
    if (b == e) {
        for(int i = 0; i < B; i++) {
            if((a[b] >> i) & 1) {
                t[n].on[i] = 1;
                t[n].off[i] = 0;
            }
            else {
                t[n].on[i] = 0;
                t[n].off[i] = 1;
            }
        }
        return;
    }

    int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
    build(l, b, mid);
    build(r, mid + 1, e);

    t[n] = merge(t[l], t[r]);
}

void upd (int n, int b, int e, int i, int j, int v) {
    push(n, b, e);
    if(b > j or e < i)
        return;
    if(i <= b and e <= j) {
        lazy[n] = v;
        push(n, b, e);
        return;
    }

    int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
    upd(l, b, mid, i, j, v);
    upd(r, mid + 1, e, i, j, v);
    t[n] = merge(t[l], t[r]);
}

node query (int n, int b, int e, int i, int j) {
    push(n, b, e);
    if(b > j or e < i) {
        node z;
        memset(z.on, 0, sizeof z.on);
        memset(z.off, 0, sizeof z.off);
        return z;
    }
    if(i <= b and e <= j) {
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

    int m; cin >> m;
    while(m--) {
    	int ty; cin >> ty;
    	if(ty == 1) {
    		int l, r;
    		cin >> l >> r;
            node ans = query(1, 1, n, l, r);
            ll sum = 0;
            for(int i = 0; i < B; i++) {
                sum += 1LL * ans.on[i] * (1 << i);
            }
    		cout << sum << '\n';
    	}
    	else {
    		int l, r, v;
    		cin >> l >> r >> v;
    		upd(1, 1, n, l, r, v);
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