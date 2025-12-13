#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e9 + 7;
using ll = long long;

void solve() {
    int n; string s, t; cin >> n >> s;

    t = s;
    reverse(s.begin(), s.end());
    map<char, vector<int>> mp1;
    map<char, vector<int>> mp2;

    for(int i = 0; i < n; i++) {
       mp1[t[i]].push_back(i);
    }

    for(int i = 0; i < n; i++) {
       mp2[s[i]].push_back(i);
    }

    vector<int> v(n);
    for(char i = 'a'; i <= 'z'; i++) {
        for(int j = 0; j < mp1[i].size(); j++) {
            v[mp2[i][j]] = mp1[i][j];
        }
    }

    o_set<int> os;
    ll ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        ans += os.order_of_key(it);
        os.insert(it);
    }

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