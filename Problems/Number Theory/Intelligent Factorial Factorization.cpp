#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;
#define new cout << '\n';
#define yes cout << "YES\n";
#define no cout << "NO\n";

bitset<110> v;

void sieve () {
    v.set();
    v[1] = false;

    for(int i = 2; i < 101; i++) {
        if(v[i]) {
            for(int j = i * i; j < 101; j += i) {
                v[j] = false;
            }
        }
    }
}
void solve(int cn) {
    int n;
    cin >> n;

    cout << "Case " << cn << ": " << n << " = ";
    
    for(int i = 2; i <= n; i++) {
        if(v[i]) {
            int exp = 0;
            for(int j = 2; j <= n; j++) {
                int x = j;
                while(x % i == 0) {
                    exp++;
                    x /= i;
                }
            }

            if(i != 2)
                cout << " * ";
            cout << i << " (" << exp << ")";
        }
    }

    new
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve();
    int t = 1, cn = 0;
    cin >> t;
    while(t--) {
        solve(++cn);
    }
    return 0;
}