#include<bits/stdc++.h>
using namespace std;

const int N = 1e7 + 7;
using ll = long long;
#define new cout << '\n';
#define yes cout << "YES\n";
#define no cout << "NO\n";

bitset<N> v;
vector<int> prime;
void sieve () {
    v.set();
    v[1] = false;

    for(int i = 2; 1LL * i * i < N; i++) {
        if(v[i]) {
            for(int j = i * i; j < N; j += i) {
                v[j] = false;
            }
        }
    }

    for(int i = 1; i < N; i++) {
        if(v[i])
            prime.push_back(i);
    }
}
void solve (int cs) {
    int n;
    cin >> n;

    int ans = 0;
    for(auto it: prime) {
        if(it > n)
            break;
        if(v[n - it] && it <= n - it) {
            ans++;
        }
    }

    cout << "Case " << cs << ": " << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve();
    int t = 1, cs= 0;
    cin >> t;
    while(t--) {
        solve(++cs);
    }
    return 0;
}