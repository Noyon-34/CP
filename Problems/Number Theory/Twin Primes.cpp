#include<bits/stdc++.h>
using namespace std;

const int N = 2e7 + 7;
using ll = long long;
#define new cout << '\n';
#define yes cout << "YES\n";
#define no cout << "NO\n";

bitset<N> v;
vector<int> prime;

void sieve() {
    v.set();
    v[1] = false;

    for (int i = 2; 1LL * i * i < N; i++) {
        if (v[i]) {
            for (ll j = 1LL * i * i; j < N; j += i) {
                v[j] = false;
            }
        }
    }

    for (int i = 2; i < N; i++) {
        if (v[i])
            prime.push_back(i);
    }
}

void solve() {
    int n;
    vector<pair<int, int>> vp;
    for(int i = 0; i < prime.size(); i++) {
        if(prime[i + 1] - prime[i] == 2)
            vp.push_back(make_pair(prime[i], prime[i + 1]));
    }
    while(cin >> n) {
        cout << "(" << vp[n - 1].first << ", " << vp[n - 1].second << ")\n";
    }
    // for(auto it: prime)
    //     cout << it << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve();
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}