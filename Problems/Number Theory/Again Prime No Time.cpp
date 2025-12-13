#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7;
using ll = long long;
#define new cout << '\n';
#define yes cout << "YES\n";
#define no cout << "NO\n";

bitset<N> v;
vector<int> prime;
void sieve() {
    v.set();
    v[1] = false;

    for (int i = 2; 1LL * i * i < N; i++) {
        if (v[i]) {
            for (int j = i * i; j < N; j += i) {
                v[j] = false;
            }
        }
    }

    for (int i = 1; i < N; i++) {
        if (v[i])
            prime.push_back(i);
    }
}
void solve(int cs) {
    int m, n;
    cin >> m >> n;

    int ans = INT_MAX;
    for(auto it: prime) {
        if(it > m)
            break;
        if(m % it == 0) {
            int e = 0;
            while(m % it == 0) {
                m /= it;
                e++;
            }
            int e_in_p = 0;
            for(int i = 1; i <= n; i++) {
                int k = i;
                if(k % it == 0) {
                    while(k % it == 0) {
                        k /= it;
                        e_in_p++;
                    }
                }
            }
            ans = min(ans, e_in_p / e);
        }
    }

    cout << "Case " << cs << ":\n";
    if(!ans)
        cout << "Impossible to divide\n";
    else
        cout << ans << '\n';
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