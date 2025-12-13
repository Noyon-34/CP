#include<bits/stdc++.h>
using namespace std;

const int N = 5e4 + 7;
using ll = long long;


int t[4 * N * 3];

void build (int node, int b, int e) {
    if(b == e) {
        t[node] = 0;
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
    int n, q; cin >> n >> q;

    int a[N], b[N], Q[N];
    set<int> s;

    // coordinate compression start
    for (int i = 1; i <= n; i++) {
    	cin >> a[i] >> b[i];
    	s.insert(a[i]);
    	s.insert(b[i]);
    }

    for (int i = 1; i <= q; i++) {
    	cin >> Q[i];
    	s.insert(Q[i]);
    }

    map<int, int> mp;
    int id = 0;
    for(auto it: s) {
    	mp[it] = ++id;
    }

    for (int i = 1; i <= n; i++) {
    	a[i] = mp[a[i]];
    	b[i] = mp[b[i]];
    }

    for (int i = 1; i <= q; i++) {
    	Q[i] = mp[Q[i]];
    }
    // coordinate compression end

    // segment tree method
    build(1, 1, id);
    for (int i = 1; i <= n; i++) {
        int l = a[i], r = b[i];

        update(1, 1, id, l, 1);
        if(r + 1 <= id)
            update(1, 1, id, r + 1, -1);
    }

    // prefix sum method 
    
    // int v[id + 1] = {0};
    // int prefix[id + 1] = {0};
    // for (int i = 1; i <= n; i++) {
    //     v[a[i]] += 1;

    //     if(b[i] + 1 <= id)
    //         v[b[i] + 1] -= 1;
    // }

    // for (int i = 1; i <= id; i++)
    //     prefix[i] = prefix[i - 1] + v[i];

    cout << "Case " << cs << ":\n";
    for (int i = 1; i <= q; i++) {
    	cout << query(1, 1, id, 1, Q[i]) << '\n';
        // cout << prefix[Q[i]] << '\n';
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