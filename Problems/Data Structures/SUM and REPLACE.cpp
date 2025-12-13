#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
using ll = long long;

int a[N];
ll t[N * 4];

void build(int n, int b, int e) {
  if (b == e) {
    t[n] = a[b];
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  build(l, b, mid);
  build(r, mid + 1, e);
  t[n] = t[l] + t[r];
}

void upd(int n, int b, int e, int i, int v) {
  if (i < b or e < i) return;
  if (b == e) {
    t[n] = v;
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  upd(l, b, mid, i, v);
  upd(r, mid + 1, e, i, v);
      t[n] = t[l] + t[r];
}

ll query(int n, int b, int e, int i, int j) {
  if (e < i or j < b) return 0;
  if (b >= i and e <= j) {
    return t[n];
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}
void solve() {
	vector<int> divs_count(N, 0);
	for(int i = 1; i <= N; i++) {
		for(int j = i; j <= N; j += i) {
			divs_count[j]++;
		}
	}

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++)
    	cin >> a[i];

    set<int> s;
    for(int i = 1; i <= n; i++) {
    	if(a[i] > 2)
    		s.insert(i);
    }
    build(1, 1, n);
    while(m--) {
    	int type, l, r; cin >> type >> l >> r;
    	if(type == 1) {
            vector<int> v;
    		auto it = s.lower_bound(l);
            while(it != s.end() && (*it) <= r) {
                upd(1, 1, n, *it, divs_count[a[*it]]);
                a[*it] = divs_count[a[*it]];
                if(a[*it] < 3) {
                    v.push_back(*it);
                }
                it++;
            }

            for(auto i: v) {
                s.erase(i);
            }
    	}
    	else {
    		cout << query(1, 1, n, l, r) << '\n';
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