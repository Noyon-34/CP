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

    int gpf = 0, x = n, cn = 0, numofdiv = 1, disprimecn = 0;
    ll totalsum = 1;

    while(x > 1) {
        int k = spf[x], pow = 0;
        int prmpow = 1;

        gpf = max(k, gpf);
        disprimecn++;

        while(x % k == 0) {
            pow++;
            cn++;
            prmpow *= k;
            x /= k;
        }

        numofdiv *= (pow + 1);
        totalsum *= ((1LL * prmpow * k - 1) / (k - 1));
    }

    cout << spf[n] << " " << gpf << " " << disprimecn << " " << cn << " " << numofdiv << " " << totalsum << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 2; i < N; i++) {
        spf[i] = i;
    }

    for(int i = 2; i < N; i++) {
        if(spf[i] == i) {
            for (int j = i; j < N; j += i){
                spf[j] = min(spf[j], i);
            }
        }
    }
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}