#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
using ll = long long;
#define new cout << '\n';
#define yes cout << "YES\n";
#define no cout << "NO\n";

bitset<N> v;
vector<int> prime;

void sieve() {
    v.set();
    v[1] = false;

    for (int i = 2; 1LL * i * i< N; i++) {
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

void solve(int cs) {
    ll n;
    cin >> n;

    ll ans = 1;
    for(auto it: prime) {
        if(1LL * it * it > n)
            break;
        if(n % it == 0) {
            int exp = 0;
            while(n % it == 0) {
                exp++;
                n /= it;
            }
            ans *= (exp + 1);
        }
    }

    if(n > 1) {
        ans *= 2;
    }
    cout << "Case " << cs << ": " << ans - 1 << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve();
    int t = 1, cs = 0;
    cin >> t;
    while(t--) {
        solve(++cs);
    }
    return 0;
}