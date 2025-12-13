#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
using ll = long long;

bitset<N> v;
vector<int> prime;
void sieve() {
    v[1] = false;
    for(int i = 2; i < N; i++) {
        v[i] = true;
    }
    for(int i = 2; i * i < N; i++) {
        if(v[i]) {
            for(int j = i * i; j < N; j += i) {
                v[j] = false;
            }
        }
    }

    for(int i = 2; i < N; i++) {
        if(v[i])
            prime.push_back(i);
    }
}
void solve() {
    int n;
    cin >> n;

    ll ans = 1;
    for(int i = 0; i < prime.size(); i++) {
        if(prime[i] > n)
            break;
        int k = n, exp = 0;
        while(k) {
            k /= prime[i];
            exp += k;
        }
        ans *= (exp + 1);
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}