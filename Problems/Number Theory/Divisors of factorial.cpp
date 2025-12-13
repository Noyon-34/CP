#include<bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;
const int mod = 1e9 + 7;

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
    cin >> n;

    int ans = 1;
    for(auto it: prime) {
        if(it > n) 
            break;
        int exp = 0;
        int k = n;
        while (k) {
            k /= it;
            exp += k;
        }

        ans = 1LL * ans * (exp + 1) % mod;
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