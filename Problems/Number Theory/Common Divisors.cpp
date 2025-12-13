#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
using ll = long long;
#define new cout << '\n';
#define yes cout << "YES\n";
#define no cout << "NO\n";

int spf[N];
void solve() {
    int n;
    cin >> n;

    vector<ll> v(n);
    vector<int> a;
    ll gcd = 0;
    int ans = 0;

    for(int i = 0; i < n; i++){
        cin >> v[i];
        gcd = __gcd(gcd, v[i]);
    }

    for(int i = 1; 1LL * i * i <= gcd; i++) {
        if(gcd % i == 0) {
            ans++;
            if(gcd / i != i)
                ans++;
        }
    }

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