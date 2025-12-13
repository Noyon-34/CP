#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
using ll = long long;

vector<double> v(N, 0);
void digits() {
    for(int i = 1; i < N; i++) {
        v[i] = v[i - 1] + log2(i);
    }
}
void solve(int cs) {
    int n, base;
    cin >> n >> base;

    cout << "Case " << cs << ": " << (int) floor(v[n] / log2(base)) + 1 << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    digits();
    int t = 1, cs = 0;
    cin >> t;
    while(t--) {
        solve(++cs);
    }
    return 0;
}