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

bool ok(int n) {
    for(int i = 2; i < n; i++) {
        if(v[i] && v[n - i])
            return true;
    }
    return false;
}

void solve() {
    for(int i = 3; i <= 10000; i += 2) {
        if(ok(i))
            cout << i << '\n';
    }
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