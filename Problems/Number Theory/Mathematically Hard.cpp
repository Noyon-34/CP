#include<bits/stdc++.h>
using namespace std;

const int N = 5e6 + 7;
using ll = long long;
#define new cout << '\n';
#define yes cout << "YES\n";
#define no cout << "NO\n";

vector<int> v(N);
void phisieve() {
    for(int i = 1; i < N; i++) {
        v[i] = i;
    }

    for(int i = 2; i < N; i++) {
        if(v[i] == i) {
            for(int j = i; j < N; j += i) {
                v[j] = v[j] / i * (i - 1);
            }
        }
    }
}
void solve(int cs) {
    int a, b;
    cin >> a >> b;

    unsigned long long ans = 0;
    for(int i = a; i <= b; i++) {
        ans += v[i] * v[i];
    }

    cout << "Case " << cs << ": " << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    phisieve();
    int t = 1, cs = 0;
    cin >> t;
    while(t--) {
        solve(++cs);
    }
    return 0;
}