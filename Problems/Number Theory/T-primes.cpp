#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
using ll = long long;
#define new cout << '\n';
#define yes cout << "YES\n";
#define no cout << "NO\n";

vector<int> prime(N, 1);
void sieve() {
    prime[0] = prime[1] = 0;
    for(int i = 2; i < N; i++) {
        if(prime[i]) {
            for(ll j = 1LL * i * i; j < N; j += i) {
                prime[j] = 0;
            }
        }
    }
}
void solve() {
    ll x, n;
    cin >> x;

    n = sqrtl(x);

    //sqrt double return kore sejonno onk somoy 100 sqrt 9.999 aste pare jeta int e 9 hoye jay sejonno ei process korle valo hoy safe thaka jay
    while(1LL * n * n < x)
        n++;
    while(1LL * n * n > x)
        n--;

    if(n * n != x) {
        no
        return;
    }
    if(prime[n])
        yes
    else
        no

    // for(auto it: prime)
    //     cout << it << " ";
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