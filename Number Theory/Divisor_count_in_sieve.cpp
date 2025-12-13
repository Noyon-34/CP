#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

void solve() {
    int n = 100;

    map<int, int> mp;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j += i) {
            mp[j]++; // Divisor sum mp[j] += i
        }
    }

    for(auto it: mp)
        cout << it.second << ' ';
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