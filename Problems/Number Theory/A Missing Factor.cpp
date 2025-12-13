#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
using ll = long long;
#define new cout << '\n';
#define yes cout << "YES\n";
#define no cout << "NO\n";

bitset<N> v;
vector<int> prime;
void sieve()
{
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
    ll n, ans;
    cin >> n;

    ll a = sqrtl(n);

    while(1LL * a * a < n)
        a++;
    while(1LL * a * a > n)
        a--;

    for(auto it: prime) {
        while(a % it == 0) {
            a /= it;
        }
        if (a == 1) {
            ans = it;
            break;
        }
    }

    if(a > 1)
        ans = a;

    cout << ans << '\n';
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