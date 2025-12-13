#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e9 + 7;
using ll = long long;

void solve() {
    int n; cin >> n;
    ll ans = 0;

    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    o_set<int> s;
    for(int i = n - 1; i >= 0; i--) {
    	b[i] = s.order_of_key(a[i]);
        s.insert(a[i]);

    }
    s.clear();
    for(int i = 0; i < n; i++) {
        s.insert(a[i] + 1);
        c[i] = i - s.order_of_key(a[i] + 1);
    }
    for(int i = 0; i < n; i++) {
        ans += 1LL * b[i] * c[i];
    }

    for(auto it: )
        cout << it << " ";
    cout << ans;
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