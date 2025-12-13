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
    vector<int> v(n);
    for(auto &it: v)
    	cin >> it;

    map<int, int> mp1, mp2;
    vector<int> l(n), r(n);
    for(int i = 0; i < n; i++) {
        mp1[v[i]]++;
        l[i] = mp1[v[i]];
    }

    for(int i = n - 1; i >= 0; i--) {
        mp2[v[i]]++;
        r[i] = mp2[v[i]];
    }
    ll ans = 0;
    o_set<pair<int, int>> os;
    for(int i = n - 1; i >= 0; i--) {
        ans += os.order_of_key({l[i], -1});
        os.insert({r[i], i});
    }

    // Brute Force
    // for(int i = 0; i < n; i++) {
    // 	int cn1 = 0, cn2 = 0;
    // 	for(int k = 0; k <= i; k++) {
    // 		if(v[k] == v[i])
    // 			cn1++;
    // 	}
    // 	for(int j = i + 1; j < n; j++) {
    // 		cn2 = 0;
    // 		for(int l = j; l <= n; l++) {
    // 			if(v[l] == v[j])
    // 				cn2++;
    // 		}
    // 		if(cn1 > cn2)
    // 			ans++;
    // 	}
    // }

    cout << ans << '\n';
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