#include<bits/stdc++.h>
using namespace std;

const int N = 1e8;
using ll = long long;
#define new cout << '\n';
#define yes cout << "YES\n";
#define no cout << "NO\n";

bitset<N> v;
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
}
void solve() {
    vector<int> a;

    for(int i = 2; i < N; i++) {
        if(v[i])
            a.push_back(i);
    }
    for(int i = 0; i < a.size(); i += 100)
        cout << a[i] << '\n';
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