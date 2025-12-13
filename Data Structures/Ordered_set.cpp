#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


const int N = 1e9 + 7;
using ll = long long;

void solve() {
    o_set<int> s;
    for(int i = 1; i <= 5; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    cout << (*s.find_by_order(0)) << '\n';
    // 0 based index e kon value ache seta return kore
    cout << s.order_of_key(4) << '\n';
    cout << s.order_of_key(10) << '\n';
    // Ei value theke strictly less than koyta value ache

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